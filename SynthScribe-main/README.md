Code, deployment instructions, and steps for configuring the Discord Developer Portal:

# SynthScribe Discord Bot

SynthScribe is a Discord bot that monitors messages in a server and sends warnings to users who mention forbidden words. It utilizes regular expressions for pattern matching and direct messages to notify users. This bot is built using the discord.py library and requires Python 3.8 or higher.

## Features

- Monitors messages in the server for forbidden words.
- Sends warning messages to users via direct messages.
- Supports multiple variations of forbidden words.
- Handles exceptions, errors, and disconnections gracefully.

## Installation

1. Clone the repository:

   ```
   git clone https://github.com/your-username/SynthScribe-Discord-Bot.git
   ```

2. Install the dependencies:

   ```
   pip install -r requirements.txt
   ```

3. Obtain a Discord bot token:

   - Go to the [Discord Developer Portal](https://discord.com/developers/applications).
   - Create a new application and navigate to the "Bot" tab.
   - Click on "Add Bot" and copy the bot token.

4. Configure the bot:

   - Open `bot.py` in a text editor.
   - Replace `'YOUR_TOKEN'` with the Discord bot token you obtained.

## Deployment

Choose a hosting solution that supports running Python applications. Some popular options include Heroku, AWS EC2, Google Cloud Platform, or a VPS (Virtual Private Server). Follow the hosting provider's instructions to deploy your bot.

Ensure you set the environment variable for the Discord bot token on your hosting platform.

## Discord Developer Portal Configuration

To configure your Discord bot in the Developer Portal:

1. Go to the [Discord Developer Portal](https://discord.com/developers/applications).
2. Select your bot application.
3. Under the "Bot" tab, enable the necessary Privileged Gateway Intents (e.g., Presence Intent and Server Members Intent).
4. Scroll up and click on "Save Changes" to save the modifications.
5. Invite the bot to your Discord server using the OAuth2 URL generated under the "OAuth2" tab. Make sure to select the appropriate permissions.

## Usage

1. Make sure the bot is deployed and running.
2. Ensure the bot has been added to your Discord server.
3. The bot will automatically monitor messages and send warnings via direct messages to users who mention forbidden words.

## Contributing

Contributions are welcome! If you have any suggestions, bug reports, or feature requests, please open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
