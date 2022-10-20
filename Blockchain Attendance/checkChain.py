def check_integrity(chain):
    for i, block in enumerate(chain):
        if i < len(chain) - 1:
            print("Checking integrity of block {}".format(i))
            if block.hash_block() != chain[i + 1].prev_hash:
                return "Chain has been modified at block index {}".format(i)
        else:
            return "Chain has not been modified"
