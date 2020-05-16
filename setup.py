from setuptools import setup, find_packages
from os import path

here = path.abspath(path.dirname(__file__))

# Get the long description from the README file
with open(path.join(here, 'README.md'), encoding='utf-8') as f:
    long_description = f.read()

setup(
    name='pi_inf442',
    version='1.0.0',
    description='Computer science project',
    long_description=long_description,
    long_description_content_type='text/markdown',
    package_dir={'': 'src_python'},
    packages=find_packages(where='src_python'),
    python_requires='>=3.5, <4',
    install_requires=['numpy', 'sklearn'],
)