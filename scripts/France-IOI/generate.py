import logging
import os
import re
import urllib.parse

from jinja2 import Environment, FileSystemLoader

logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

FRANCE_IOI_SOLUTIONS_DIR = 'solutions/France-IOI'
TEMPLATE_FILE = 'README.template.md'
TEMPLATE_DIR = 'scripts/France-IOI'

def generate_data_from_folder(path):
    data = {}

    # Verify solutions directory exists
    if not os.path.exists(path):
        logging.error(f'Solutions directory "{path}" does not exist.')
        return
    
    # Walk through level directories
    for level_dir in sorted(os.listdir(path)):
        level_path = os.path.join(path, level_dir)
        if not os.path.isdir(level_path):
            continue
        
        level_data = {}
        
        for chapter_dir in sorted(os.listdir(level_path)):
            chapter_path = os.path.join(level_path, chapter_dir)
            if not os.path.isdir(chapter_path):
                continue
            
            chapter_data = {"parts": [], "problems": []}

            # Check for parts (subdirectories within a chapter)
            for part_or_file in sorted(os.listdir(chapter_path)):
                part_or_file_path = os.path.join(chapter_path, part_or_file)
                if os.path.isdir(part_or_file_path):
                    # Handle parts
                    part_data = []
                    for idx, file in enumerate(sorted(os.listdir(part_or_file_path))):
                        if file.endswith('.cpp') or file.endswith('.c'):
                            [problem_title, extension] = file.rsplit('.', 1)
                            problem_id = idx + 1
                            part_data.append({"id": problem_id, "title": problem_title, "extension": extension})
                    if part_data:
                        chapter_data["parts"].append({"part": part_or_file, "problems": part_data})
                else:
                    # Handle problems directly in the chapter
                    if part_or_file.endswith('.cpp') or part_or_file.endswith('.c'):
                        [problem_title, extension] = part_or_file.rsplit('.', 1)
                        problem_id = len(chapter_data["problems"]) + 1
                        chapter_data["problems"].append({"id": problem_id, "title": problem_title, "extension": extension})

            if chapter_data["parts"] or chapter_data["problems"]:
                level_data[chapter_dir] = chapter_data

        if level_data:
            data[level_dir] = level_data

    return data

def escape_internal_link(text):
    # Trim leading/trailing spaces
    text = text.strip()
    # Convert to lowercase
    text = text.lower()
    # Remove characters that are not word characters, hyphens, or spaces
    text = re.sub(r'[^\w\- ]+', '', text)
    # Replace spaces with hyphens
    text = re.sub(r'\s', '-', text.strip())
    # Remove trailing hyphens
    text = re.sub(r'\-+$', '', text)
    return text

def escape_external_link(text):
    return urllib.parse.quote(text)

if __name__ == '__main__':
    # Load the template
    logging.info('Loading the template')
    env = Environment(loader=FileSystemLoader(TEMPLATE_DIR))
    env.filters['escape_internal_link'] = escape_internal_link
    env.filters['escape_external_link'] = escape_external_link
    template = env.get_template(TEMPLATE_FILE)

    # Generate the data from the folder structure
    logging.info('Starting content generation')
    data = generate_data_from_folder(FRANCE_IOI_SOLUTIONS_DIR)

    # Render the README with data
    logging.info('Rendering the README')
    output = template.render(levels=data)

    # Save the generated README
    output_file = f'{FRANCE_IOI_SOLUTIONS_DIR}/README.md'
    logging.info(f'Writing the generated content to {output_file}')
    with open(output_file, 'w') as file:
        file.write(output)

    logging.info(f'Readme generation completed')
