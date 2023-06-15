import sqlite3
import pandas as pd
conn = sqlite3.connect('anuhska.db')
conn.execute("Create table if not exists item(itemid integer primary key, name text not null, price integer not null)")
conn.execute("Create table if not exists cart(itemid integer primary key, quantity integer not null)")
conn.execute("delete from item")
conn.execute("delete from cart")
items=[(1,'eggs',15),(2,'bacon',25),(9,'salad',60),(12,'sausage',100)]
conn.executemany("insert into item values(?,?,?)",items)
conn.commit()
print("Add items to you cart by entering the item id and the quantity you want:")
itemids=[]
ite=conn.execute("select itemid from item")
for i in ite:
    itemids.append(list(i)[0])
while True:
    itemid = int(input("Enter item id(Enter 0 to stop giving entries):"))
    if(itemid==0):
        break
    if itemid not in itemids:
        print("Enter a valid item id!!! The item you entered doesn't exist.")
        print("Valid item ids are:",itemids)
        continue
    quantity = int(input("Enter quantity :"))
    cart_itemids=conn.execute("select itemid from cart")
    if itemid not in cart_itemids:
        conn.execute("insert into cart values (?,?)",(itemid,quantity))
    else:
        conn.execute("update cart set quantity= quantity + ? where itemid= ? ",(quantity,itemid))
    conn.commit()
rows=conn.execute("Select * from cart")
df = pd.DataFrame(rows, columns=['itemid','quantity'])
print(df)
while True:
    flag=input("Do u wanna change any quantity?[y/n]:")
    if flag=='y':
        itemid=int(input("Enter item id:"))
        quantity=int(input("Enter new quantity:"))
        conn.execute("update cart set quantity= ? where itemid= ? ",(quantity,itemid))
        conn.commit()
    else:
        break
rows=conn.execute("Select * from cart")
df = pd.DataFrame(rows, columns=['itemid','quantity'])
print(df)
while True:
    flag=input("Do u wanna delete any item from cart?[y/n]:")
    if flag=='y':
        itemid=int(input("Enter item id:"))
        conn.execute("delete from cart where itemid= ? ",(itemid,))
        conn.commit()
    else:
        break
rows=conn.execute("Select * from cart")
df = pd.DataFrame(rows, columns=['itemid','quantity'])
print(df)
print("Now let's calculate total price!!!")
print("Here is your final bill:")
rows=conn.execute("select itemid, name, quantity, price, (quantity * price) AS total_price from cart natural join item")
conn.commit()
df = pd.DataFrame(rows, columns=['itemid','name','quantity','price','total_price'])
print(df)
final_price = df['total_price'].sum()
print("Total price of all items in cart:", final_price)
conn.close()