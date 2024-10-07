import os
import logging

from jinja2 import Template

logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

FRANCE_IOI_SOLUTIONS_DIR = 'solutions/France-IOI'
TEMPLATE_FILE = 'scripts/France-IOI/README.template.md'

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
        
        # Walk through chapter directories within each level
        for chapter_dir in sorted(os.listdir(level_path)):
            chapter_path = os.path.join(level_path, chapter_dir)
            if not os.path.isdir(chapter_path):
                continue
            
            problems = []

            # Iterate over files and assign unique problem IDs based on index
            for idx, file in enumerate(sorted(os.listdir(chapter_path))):
                if file.endswith('.cpp'):
                    problem_title = file.rsplit('.', 1)[0]  # Extract problem title
                    problem_id = idx + 1 # Assign problem ID as index
                    problems.append({"id": problem_id, "title": problem_title})

            if problems:
                level_data[chapter_dir] = problems

        if level_data:
            data[level_dir] = level_data

    return data

if __name__ == '__main__':
    # Load the template
    logging.info('Loading the template')
    with open(TEMPLATE_FILE, 'r') as file:
        template = Template(file.read())

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
