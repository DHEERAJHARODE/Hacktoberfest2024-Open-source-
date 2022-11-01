#Q26)
#Program to create a table
import mysql.connector as msql
mcon=msql.connect(host="localhost",user="root", passwd="", database="outfit")
if mcon.is_connected():
    print("Sucessfully connected")
curs=mcon.cursor()
curs.execute("CREATE TABLE student (id INT, name VARCHAR(255));")
curs.execute("SHOW TABLES;")
for table in curs:
	print(table)
