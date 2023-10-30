import os
import sys
import csv

source_path = sys.argv[1]
source_name = source_path.split(".")[0]
source_extension = source_path.split(".")[1]

destination_file = sys.argv[2]
destination_name = destination_file.split(".")[0]
destination_extension = destination_file.split(".")[1]

if source_extension == 'csv':
    with open(source_path, 'r') as csvfile:
        csvreader = csv.reader(csvfile)
        data = list(csvreader)

    for i, row in enumerate(data):
        with open(f'tests/{destination_extension}/{destination_name}{i}.in', 'w') as in_file:
            in_file.write(row[0])
        with open(f'tests/{destination_extension}/{destination_name}{i}.out', 'w') as out_file:
            out_file.write(row[1])