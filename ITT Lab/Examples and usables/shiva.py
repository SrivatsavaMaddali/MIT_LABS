import sqlite3
from datetime import date
conn = sqlite3.connect('shiva.db')
conn.execute("create table if not exists salesman(salesmanid integer primary key,commission integer not null, name text not null, dateofjoin date not null)")
list = []
while True:
    id = int(input("Enter Salesman ID(Enter 0 to stop giving entries):"))
    if(id==0):
        break
    commission = int(input("Enter commission :"))
    name = input("Enter name:")
    dateofjoin = input("Enter date of joining (YYYY-MM-DD):")
    list.append((id,commission,name,dateofjoin))
cursor = conn.executemany("Insert into salesman values(?,?,?,?)",list)
conn.commit()
presentdate = date.today() 
cursor = conn.execute("alter table salesman add column experience integer")
cursor = conn.execute("update salesman set experience = ? - dateofjoin",(presentdate,))
conn.commit()

print("The salesman table (with experience) is:")
cursor2 = conn.execute("select * from salesman")
for row in cursor2:
    print(row)

cursor3 = conn.execute("update salesman set commission = 1.5*commission where experience > 5")
cursor3 = conn.execute("select * from salesman order by experience desc")
print("The salesman table with updated commission in descending order of experience is:")
for row in cursor3:
    print (row)
conn.close()