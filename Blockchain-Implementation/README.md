## How to run: 

### First we need to make a virtual environment:
```shell
$ virtualenv venv
```

### Then we activate the virtual environment:
```shell
$ source venv/bin/activate
```
(if on `linux` or `mac`)
**OR**
```shell
$ ./venv/Scripts/activate
```
(if on `windows`)

### We install the required dependencies for this project:
```shell
$ pip install -r /requirements.txt
```
### Run the following command to get the Flask API started to get the endpoints to the Blockchain Network:
```shell
python3 main.py
```
The following command will run the `main.py` file on your localhost at the port `8000`.
On your browser open the link `http://localhost:8000/<endpoints>`.

You are all set to view the blockchain and use it.

## The endpoints and their functionalities are listed below :

### GET endpoints:

`/chain`: displays info about the whole chain

 `/mine`:  to add all the left transactions to the block and add it to the block

`/time`:  to display the time of each transaction
                                
### POST endpoints:

`/new_transaction`: to add a new transaction to the pool

`/add_block`:       to add a whole new block to the blockchain (multiple transactions in a block)

`/register_node`:   to register a node to the network

`/register_with`:   to register and sync a new node to the network
## The blockchain has the following format:
```json
{
    "length": 3,
    "chain": [
        {
            "index": 0,
            "transactions": [],
            "timestamp": 0,
            "previous_hash": "0",
            "nonce": 0,
            "hash": "6dbf23122cb5046cc5c0c1b245c75f8e43c59ca8ffeac292715e5078e631d0c9"
        },
        {
            "index": 1,
            "transactions": [
                {
                    "Customer": "neil",
                    "Amount": "150",
                    "Drink": "Irish Frappe",
                    "timestamp": "Sat Sep 25 21:38:10 2021"
                }
            ],
            "timestamp": "Sat Sep 25 21:38:15 2021",
            "previous_hash": "6dbf23122cb5046cc5c0c1b245c75f8e43c59ca8ffeac292715e5078e631d0c9",
            "nonce": 118,
            "hash": "00a42f2cf32658666abac1e6dca4703f0195948914f74bfabba49831a8f07c82"
        },
        {
            "index": 2,
            "transactions": [
                {
                    "Customer": "atishay",
                    "Amount": "140",
                    "Drink": "Mocha Frappe",
                    "timestamp": "Sat Sep 25 21:40:29 2021"
                },
                {
                    "Customer": "mudit",
                    "Amount": "400",
                    "Drink": "Tea Latte",
                    "timestamp": "Sat Sep 25 21:40:55 2021"
                }
            ],
            "timestamp": "Sat Sep 25 21:41:00 2021",
            "previous_hash": "00a42f2cf32658666abac1e6dca4703f0195948914f74bfabba49831a8f07c82",
            "nonce": 136,
            "hash": "00f12d8cc4223fb71b1c330ce17be42bd4822422daf2325b081b0613010f23b2"
        }
    ],
    "peers": []
}
```
## Our blockchain has the following functionalities:

  - Get all the information of the Blockchain for the User.
  - Immutability of the Blockchain (No one can change the already committed information)  
  - The timestamp of each Transaction is readily available using both the chain endpoint and time endpoint
  - All the completed transactions are stored in the blockchain, we have both a verified (mined) pool as well as pending(uncomfirmed) transactions.
  - We have also implemented a basic Proof of Work Algorithm where the hash of the block has to start with x numbers of 0's. We can set the difficulty (x) using the difficulty parameter in the BlockChain class. We took reference from the following code for the same implementation \[[*Reference*](https://www.geeksforgeeks.org/create-simple-blockchain-using-python/)]
  - The value of each nonce is calculated using the Proof of Work algorithm
  - Each Block may contain multiple transactions, it can also contain a single transaction
  - Each Block can have a maximum of 10 transactions after which it will automatically mine the block from the unconfirmed transactions pool.
  - Cryptographic hash is been calculated using the `hashlib` with `SHA256` algorithm in python  
  - The hash of the block and its previous block is available in the blockchain
