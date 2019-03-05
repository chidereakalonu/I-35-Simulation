# -*- coding: utf-8 -*-

import os
import sys
import cloud_sptheme as csp

sys.path.insert(0, os.path.abspath('.'))

# -- Project information -----------------------------------------------------

project = 'PoolBalls'
copyright = '2019, Roie R. Black'
author = 'Roie R. Black'

version = '0.0.1'
release = '0.0.1'

# -- General configuration ---------------------------------------------------

extensions = [
    'sphinx.ext.githubpages',
]
templates_path = ['_templates']
source_suffix = '.rst'
master_doc = 'index'
language = None
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']
pygments_style = None

# -- Options for HTML output -------------------------------------------------
html_theme = 'cloud'
html_theme_path = [csp.get_theme_dir()]
html_theme_options = { "roottarget": "index" }
html_static_path = ['_static']
