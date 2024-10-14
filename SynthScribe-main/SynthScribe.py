import asyncio
import re
import random
import difflib

import discord
from discord.ext import commands

intents = discord.Intents.all()
intents.message_content = True
bot = commands.Bot(command_prefix='!', intents=intents)

randomMessages = [
    'Zindagi me Kuch accha karo meri jaan.',
    'Goli Beta Masti Nahi',
    'Abe oye, chup kar jaake',
    'Bhai, tu kya kar raha hai?',
    'Abe saale, dimaag ka dahi mat kar',
    'Chal be, nikal yaha se',
    'Kya bakwaas kar raha hai be?',
    'Abe chup kar, kuch kaam dhanda karle',
    'Neem ka patta kadwa hai, aur tu bhi',
    'Chalega be, nikal yaha se',
    'Oye chup kar, kuch kaam karle',
    'Abey basti ke kutte, chup kar'
]

forbiddenWords = [
    'bestie',
    'pizza',
    'lodu',
    'gandu',
    'aman',
    'khila',
]

@bot.event
async def on_ready():
    print(f'{bot.user} has connected to Discord!')

@bot.event
async def on_message(message):
    if message.author == bot.user:
        return

    # Convert message to lowercase
    messageContent = message.content.lower()

    messageWords = messageContent.split()
    for word in messageWords:
        closeMatches = difflib.get_close_matches(word, forbiddenWords, n=1, cutoff=0.8)
        if len(closeMatches) > 0:
            response = random.choice(randomMessages)
            await message.author.send(response)
            break

    await bot.process_commands(message)

@bot.event
async def on_error(event, *args, **kwargs):
    print(f'Error in event {event}: {args[0]}')

@bot.event
async def on_disconnect():
    print('Disconnected from Discord!')
