import csv
from xml.etree import ElementTree as ET

def remove_tag1(xml_str):
    try:
        # Parse the XML content
        root = ET.fromstring(xml_str)
        # Remove all occurrences of the tag1 element
        for tag1 in root.findall('.//tag1'):
            parent = tag1.getparent()
            if parent is not None:
                parent.remove(tag1)
        # Convert back to string
        return ET.tostring(root, encoding='unicode')
    except ET.ParseError:
        return xml_str

def remove_duplicates(input_file, output_file):
    seen = set()
    unique_rows = []

    with open(input_file, 'r', newline='') as infile:
        reader = csv.reader(infile)
        for row in reader:
            xml_content = row[3]
            relevant_xml = remove_tag1(xml_content)
            # Create a tuple of the relevant parts (ignoring the first three fields)
            relevant_part = (row[3], relevant_xml)
            if relevant_part not in seen:
                seen.add(relevant_part)
                unique_rows.append(row)

    with open(output_file, 'w', newline='') as outfile:
        writer = csv.writer(outfile)
        writer.writerows(unique_rows)

# Specify the input and output file names
input_file = 'yourfile.csv'
output_file = 'unique_file.csv'

# Remove duplicates and save the result
remove_duplicates(input_file, output_file)