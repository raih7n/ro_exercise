import json
import logging
import sys
from rich.logging import RichHandler
from rich.console import Console


def start():
    console = Console()
    console.print("Pythonic Ro interactions parser v1")

    with open('interactions.json') as fp:
        jdata = json.load(fp)

    if len(sys.argv) < 2:
        console.print("Type exit to quit")
        while True:
            input = console.input("Enter drugs: ")
            drugs = list(map(str.lower, input.split()))
            if 'exit' in drugs:
                exit()

            find_interactions(jdata, drugs)
    else:
        find_interactions(jdata, sys.argv)


def find_interactions(jdata, drugs):
    # Find all interactions
    interactions = []
    for entry in jdata:
        jdrugs = entry['drugs']
        if len(list(set(drugs) & set(jdrugs))) > 1:
            interactions.append(entry)

    log = logging.getLogger('main')

    if interactions:
        for interaction in interactions:
            idrugs = interaction['drugs']
            log.warning("Interaction with {} & {}\nSeverity: {}\nDescription: {}".format(
                idrugs[0], idrugs[1], interaction['severity'], interaction['description'])
            )
    else:
        log.info("No interactions found")


if __name__ == '__main__':
    logging.basicConfig(
        level="NOTSET", format="%(message)s", datefmt="[%X]", handlers=[RichHandler(show_path=False, show_time=False)]
    )

    start()
