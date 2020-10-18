def main():
    myMsg="transposition cipher"
    mykey=10
    ciphertext=ecrptmsg(mykey,myMsg)
    print("cipher text:")
    print(ciphertext+"|")
def ecrptmsg(key,msg):
    ciphertext=['']*key
    for col in range(key):
        position=col
        while position<len(msg):
            ciphertext[col]+=msg[position]
            position+=key
    return ''.join(ciphertext)
if __name__=='__main__':
    main()
