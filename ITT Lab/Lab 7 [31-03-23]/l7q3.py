import sqlite3

# Establish connection to the database
conn = sqlite3.connect('students.db')
cursor = conn.cursor()

# Take regno input from user
regno = input("Enter student regno: ")

# Query the database for the student details with the given regno
cursor.execute("SELECT * FROM students WHERE regno=?", (regno,))
rows = cursor.fetchall()

# Display the student details if found, else show error message
if rows:
    print("Student details:")
    for row in rows:
        print(f"Reg No: {row[1]}")
        print(f"Branch: {row[2]}")
        print(f"Semester: {row[3]}")
        print(f"Section: {row[4]}")
        print(f"CGPA: {row[5]}")
        print(f"Email: {row[6]}")
else:
    print(f"No student found with regno {regno}")

# Close the connection to the database
conn.close()
