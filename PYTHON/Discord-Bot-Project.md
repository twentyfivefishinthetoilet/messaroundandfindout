<h2>Making (and scripting) a Discord bot with Python <label style="font-size: 14px;">by @twentyfivefishinthetoilet</label></h2>

This project is a step by step tutorial on how to make a Discord bot from the ground up. We'll be using the `discord` library, which you can install by using `pip` in the command prompt with every other library.

    pip install discord

*<small>["discord" Python library credits...](https://pypi.org/project/discord.py/)</small>*

## Making the bot

**Step 1.** Head on over to the [Discord Developer Portal](https://discord.com/developers/applications) and sign in to your Discord account. Once you're signed in, click that blue "New Application" button at the top right corner of your screen. Type in your app's name. *Note that you can change this name later.*

**Step 2.** Great, we made our bot! Let's edit it so we can actually use it. Change the name and description as needed then click `OAuth2`. Scroll down until you see `OAuth2 URL Generator` and then click the box that says `bot`.

<img src="https://github.com/twentyfivefishinthetoilet/messaroundandfindout/blob/main/PYTHON/Discord%20Bot%20Project%20Images/Step2.png?raw=true">

Scroll down a little further, then click the `Send Messages` and `Use Slash Commands` checkboxes.

<img src="https://github.com/twentyfivefishinthetoilet/messaroundandfindout/blob/main/PYTHON/Discord%20Bot%20Project%20Images/Step2B.png?raw=true">



## Scripting the bot

    import discord
    from discord.ext import commands

