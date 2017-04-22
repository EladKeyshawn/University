import json
import os.path
import subprocess


class ProcessesDisplayer:
    all_processes_data = []
    ps_paramters = ['PID', 'TTY', 'TIME', 'CMD']
    filename = ''

    def __init__(self, filename):
        self.filename = filename
        ps = subprocess.Popen("ps -U 0", shell=True, stdout=subprocess.PIPE)
        all_ps_string = ps.stdout.read()
        ps.stdout.close()
        ps.wait()
        lines = all_ps_string.split('\n')[1:]
        for line in lines:
            process = [x for x in line.split(' ') if x != '']
            process_dict = dict(zip(self.ps_paramters, process))
            self.all_processes_data.append(process_dict)

    def saveToJsonFile(self):
        with open(self.filename, 'w') as outstream:
            json.dump(self.all_processes_data, outstream)

    def readJsonFile(self):
        if os.path.isfile(self.filename):
            with open(self.filename) as file_data:
                data = json.load(file_data)
                print data


def main():
    processDisplayer = ProcessesDisplayer("jsondata.json")
    processDisplayer.saveToJsonFile()
    processDisplayer.readJsonFile()



main()