from pykd import *
from os.path import expanduser

res = pykd.dbgCommand("lm")
dprintln(res[:400])
