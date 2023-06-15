import sqlite3

# Connect to the database
conn = sqlite3.connect('students.db')

# Prompt the user for the student ID and new CGPA
student_id = input("Enter the student ID: ")
new_cgpa = input("Enter the new CGPA: ")

# Update the database with the new CGPA
conn.execute("UPDATE students SET CGPA = ? WHERE ID = ?", (new_cgpa, student_id))
conn.commit()

# Display a message indicating the update was successful
print("CGPA updated successfully.")

# Close the connection
conn.close()
