
##################### KEEP THIS ######################
"""
This import and function is necessary to import the
module in the scripts folder
"""
import sys
sys.path.insert(0, '..')
######################################################

from scripts import algo

def testAlgo():
    """
    Test description
    """

    assert "hello world 4" == algo.get_text(4)
