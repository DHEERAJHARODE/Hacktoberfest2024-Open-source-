import datetime as dt
from block import *


def create_genesis_block():
    return [Block(0, dt.datetime.now(), "Genesis Block", "0")]
