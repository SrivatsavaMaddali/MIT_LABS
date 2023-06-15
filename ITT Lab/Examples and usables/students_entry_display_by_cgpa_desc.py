import sqlite3
conn=sqlite3.connect('trying.db')
conn.execute('''Create table if not exists students(regno integer primary key,
                                             name text not null,
                                             branch text not null,
                                             section text null,
                                             semester integer not null,
                                             cgpa real not null);''')
records=[]
while True:
    regno = int(input("Enter student regno(Enter 0 if you want to stop giving entries):"))
    if(regno==0):
        break
    name = input("Enter student name:")
    branch = input("Enter student branch:")
    section = input("Enter student section:")
    semester = int(input("Enter student semester:"))
    cgpa = float(input("Enter student cgpa:"))
    records.append((regno,name,branch,section,semester,cgpa))
conn.executemany("insert into students(regno,name,branch,section,semester,cgpa) values(?,?,?,?,?,?)",records)
conn.commit()
if sqlite3.IntegrityError:
    print("Unique contraint breaking!!!! Recheck details and enter correct details...")
rows=conn.execute("select * from students order by cgpa desc")
print("Student records sorted by CGPA in descending order:")
for row in rows:
    print(row)
conn.close()