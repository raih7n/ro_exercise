# Ro Exercise

### Technical interview exercise/project for Ro

given an input of medications, this program will detected any interactions between as determined by interactions.json

Sample input

	python3 ro.py nitroglycerin sildenafil nicotine

or

    python3 ro.py
    Pythonic Ro interactions parser v1
    Type exit to quit
    Enter drugs: nitroglycerin sildenafil nicotine

Sample output:
~~~text
WARNING  Interaction with sildenafil & nitroglycerin
Severity: contraindication 
Description: Phosphodiesterase-5 (PDE5) inhibitors may potentiate the hypotensive effect of organic nitrates.

WARNING  Interaction with sildenafil & nicotine
Severity: minor
Description: The metabolism of Sildenafil can be decreased when combined with Nicotine.
~~~

## Credits
The following are used without modification. Credits to their authors. Libraries can be installed via pip or your prefered package manager
- [rich][github.rich]  
Rich is a Python library for rich text and beautiful formatting in the terminal.


[//]: # (Hyperlink IDs)
[github.rich]: https://github.com/willmcgugan/rich