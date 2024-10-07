import os
import logging

from jinja2 import Template

logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

CSES_SOLUTIONS_DIR = 'solutions/CSES'
TEMPLATE_FILE = 'scripts/CSES/README.template.md'

def generate_data_from_folder(path):
    data = {}

    # Verify solutions directory exists
    if not os.path.exists(path):
        logging.error(f'Solutions directory "{path}" does not exist.')
        return
    
    # Walk through the CSES folder structure
    for root, dirs, files in sorted(os.walk(path)):
        category = os.path.basename(root)
        problems = []
        
        # Scan for .cpp files
        for file in sorted(files):
            if file.endswith('.cpp'):
                problem_id, problem_title = file.split(" - ", 1) # Extract problem ID and title from the filename
                problem_title = problem_title.rsplit('.', 1)[0]  # Remove the .cpp extension
                problems.append({"id": problem_id, "title": problem_title})
        
        if problems:
            data[category] = problems

    return data

if __name__ == '__main__':
    # Load the template
    logging.info('Loading the template')
    with open(TEMPLATE_FILE, 'r') as file:
        template = Template(file.read())

    # Generate the data from the folder structure
    logging.info('Starting content generation')
    data = generate_data_from_folder(CSES_SOLUTIONS_DIR)

    # Render the README with data
    logging.info('Rendering the README')
    output = template.render(categories=data)

    # Save the generated README
    output_file = f'{CSES_SOLUTIONS_DIR}/README.md'
    logging.info(f'Writing the generated content to {output_file}')
    with open(output_file, 'w') as file:
        file.write(output)

    logging.info(f'Readme generation completed')
