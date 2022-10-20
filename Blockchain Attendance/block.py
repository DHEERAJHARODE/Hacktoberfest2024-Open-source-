import hashlib


class Block:
    def __init__(self, index, timestamp, data, prev_hash):
        self.index = index
        self.timestamp = timestamp
        self.data = data
        self.prev_hash = prev_hash
        self.hash = self.hash_block()

    def hash_block(self):
        sha = hashlib.sha256()
        sha.update(str(self.index).encode() + str(self.timestamp).encode() + str(self.data).encode() + str(
            self.prev_hash).encode())
        return sha.hexdigest()
