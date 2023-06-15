import sqlite3

# Connect to the database
conn = sqlite3.connect('students.db')

# Create a table for student records
conn.execute('''CREATE TABLE IF NOT EXISTS Students
               (ID INTEGER PRIMARY KEY,
                RegNo TEXT NOT NULL,
                Branch TEXT NOT NULL,
                Semester INTEGER NOT NULL,
                Section TEXT NOT NULL,
                CGPA REAL NOT NULL,
                Email TEXT NOT NULL);''')
students = []
while True:
    id = input("Enter id: ")
    if id == '':
        break
    reg_no=input("Enter reg no:")
    branch = input("Enter branch: ")
    semester = int(input("Enter semester: "))
    section = input("Enter section: ")
    cgpa = float(input("Enter CGPA: "))
    email = input("Enter email: ")
    students.append((id,reg_no, branch, semester, section, cgpa, email))

conn.executemany("INSERT INTO Students (ID, RegNo, Branch, Semester, Section, CGPA, Email) VALUES (?, ?, ?, ?, ?, ?, ?)", students)
conn.commit()

# Fetch and display student records sorted by CGPA in descending order
rows = conn.execute("SELECT * FROM Students ORDER BY CGPA DESC")
print("Sorted student records:")
for row in rows:
    print(row)

# Close the database connection
conn.close()
