from block import *
import datetime as dt


def next_block(last_block, data):
    this_index = last_block.index + 1
    this_timestamp = dt.datetime.now()
    # A one level deep copy of data has been created since data is modified repeatedly
    # in the calling function and if data is a direct pointer, it leads to modification
    # of old data in the chain.
    this_data = data[:]
    this_prev_hash = last_block.hash
    return Block(this_index, this_timestamp, this_data, this_prev_hash)


def add_block(form, data, blockchain):
    data.append([])
    i = 1
    while form.get("roll_no{}".format(i)):
        data[-1].append(form.get("roll_no{}".format(i)))
        i += 1
    previous_block = blockchain[-1]
    block_to_add = next_block(previous_block, data)
    blockchain.append(block_to_add)
    previous_block = block_to_add
    return "Block #{} has been added to the blockchain!".format(block_to_add.index)
