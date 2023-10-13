import discord
from discord.ext import commands
import csv
import os

intents = discord.Intents.default()
intents.message_content = True
client = commands.Bot(command_prefix='.',intents=intents)

# Global Var
FILENAME = "auction.csv"
CURRENTUSER = None
SOLD = True
GUILDID = None
CURRENTPRICE = 0
LastBidder = None

if os.path.isfile(f"{FILENAME}"):
    pass
else:
    field = ["Username", "UserID", "Baseprice", "Sold", "Balance", "CurrentPrice", "SoldTo"]
    with open(FILENAME, "w") as csvFile:
        csvWriter = csv.writer(csvFile)
        csvWriter.writerow(field)

def checkSold():
    global SOLD, CURRENTUSER, GUILDID
    with open(FILENAME, 'r') as csvFile:
        details = csv.reader(csvFile)
        for detail in details:
            if len(list(detail)) > 1:
                if detail[3] == "False":
                    SOLD = False
                else:
                    continue
def raiseBid(user: discord.Member, amount, details):
    global FILENAME
    for detail in details:
        if len(list(detail)) > 1:
            if detail[1][1].isdigit():
                userId = int(detail[1])
                if user.id == userId:
                    if detail[5].isdigit():
                        detail[5] = int(detail[5])
                        detail[5] += amount
                        print("Bid has beed raised...")

@client.event
async def on_ready():
    global CURRENTUSER, FILENAME, CURRENTPRICE
    with open(FILENAME, 'r') as csvFile:
        details = csv.reader(csvFile)
        for detail in details:
            if len(list(detail)) > 1:
                if detail[3] == "False":
                    userId = int(detail[1])
                    user = await client.fetch_user(userId)
                    CURRENTUSER = user
                    CURRENTPRICE = int(detail[5])
                else:
                    continue

@client.command()
@commands.check_any(commands.is_owner(),commands.has_role("Thanedaar"))
async def auction(ctx, user: discord.Member, price):
    global SOLD, FILENAME, CURRENTUSER, CURRENTPRICE
    if SOLD:
        with open(FILENAME, "r") as csvfile:
            details = list(csv.reader(csvfile))
            for detail in details:
                if len(detail) > 1:
                    if detail[1] == user.id:
                        if detail[3]:
                            await ctx.send(f"{user.mention} has already been sold")
                            return
                        elif detail[3]:
                            await ctx.send(f"For {user.mention} auction is going on")
                            return
        CURRENTUSER = user
        detail = [user.name, user.id, price, False, None, price, None]
        with open(FILENAME, 'a') as csvFile:
            writer = csv.writer(csvFile)
            writer.writerow(detail)
        message = discord.Embed(
            title="Acution",
            description=f"Auction has been started for {user.mention} with the base price of {price} Crore",
            colour = discord.Color.yellow()
        )
        await ctx.send(embed=message)
        SOLD = False
        CURRENTPRICE = price
    else:
        await ctx.send("Another auction is already going on.")

@client.command()
@commands.check_any(commands.is_owner(),commands.has_role("Thanedaar"))
async def addMoney(ctx, user: discord.Member, amount):
    global FILENAME
    with open(FILENAME, "r") as csvfile:
            details = list(csv.reader(csvfile))
            for detail in details:
                if len(detail) > 1:
                    if detail[0] == user.name:
                        if detail[2] != None:
                            await ctx.send(f"{user.mention} is already in Auction")
                            return
    detail = [user.name, user.id, None, None, amount, None, None]
    with open(FILENAME, 'a') as csvFile:
        writer = csv.writer(csvFile)
        writer.writerow(detail)
    await ctx.send(f"{amount} crores has been added to the balance of {user.mention}")

@client.command()
async def bid(ctx):
    global FILENAME, CURRENTUSER, SOLD, CURRENTPRICE
    checkSold()
    if not SOLD:
        r = csv.reader(open(FILENAME)) # Here your csv file
        details = list(r)
        for detail in details:
            if len((list(detail))) > 1:
                if detail[1][1].isdigit():
                    userId = int(detail[1])
                    if userId == ctx.message.author.id:
                        if detail[4].isdigit():
                            detail[4] = int(detail[4])
                            if int(detail[4]) >= CURRENTPRICE:
                                detail[4] -= 1
                                print("Bal has been reduced...")
                                raiseBid(CURRENTUSER, 1, details)
                                await ctx.send(f"Bid on {CURRENTUSER.mention} has been raised by {ctx.message.author.mention}")
                            else:
                                await ctx.send(f"{ctx.message.author.mention} You don't have enough balace to place a bid")
        writer = csv.writer(open(FILENAME, 'w'))
        writer.writerows(details)
    else:
        ctx.send(f"Previous Player has already been sold.")

@client.command()
async def sold(ctx):
    global SOLD, CURRENTUSER
    SOLD = True
    r = csv.reader(open(FILENAME)) # Here your csv file
    details = list(r)
    for detail in details:
        if len(list(detail)) > 1:
            if detail[1][1].isdigit():
                if int(detail[1]) == CURRENTUSER.id:
                    detail[3] = SOLD
    writer = csv.writer(open(FILENAME, 'w'))
    writer.writerows(details)
    await ctx.send(f"{CURRENTUSER.mention} has been sold")

@client.command()
async def bal(ctx):
    bal = None
    r = csv.reader(open(FILENAME)) # Here your csv file
    details = list(r)
    for detail in details:
        if len(list(detail)) > 1:
            if detail[1][1].isdigit():
                if int(detail[1]) == ctx.message.author.id:
                    bal = int(detail[4] )
    if bal != None and bal != 0:
        await ctx.send(f"{ctx.message.author.mention} You have a balace of amout: {bal} Crore")
    else:
        await ctx.send(f"{ctx.message.author.mention} You don't have any balance")


client.run('MTA5Mzc2Mzk1NTQzODE0NTU5Ng.G7XDhE.ctMEPHc4sHRnfHTRb-MOlNyoS9adHGlwEq4D4A')