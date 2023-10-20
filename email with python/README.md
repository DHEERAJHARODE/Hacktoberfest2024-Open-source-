## Email Sender Script

This Python script allows you to send email notifications to recipients using the `smtplib` library and a CSV file containing recipient information. The script reads an email template from a file, substitutes placeholders in the template with data from the CSV file, and sends personalized emails to the recipients.

### Program Components

- **Libraries and Modules**:
  - The script utilizes various Python libraries and modules, including:
    - `smtplib`: Used to manage the SMTP email server and facilitate email transmission.
    - `csv`: Employed for reading recipient data from a CSV file.
    - `string.Template`: Responsible for creating email templates with placeholders.
    - `email.mime`: Utilized to construct MIME (Multipurpose Internet Mail Extensions) email messages.

- **`read_template` Function**:
  - This function reads an email template from a specified file (`filename`). It loads the template content as a string and returns it as a `Template` object.

- **`main` Function**:
  - The primary function that orchestrates the email sending process.
  - It loads the email template from a file and configures the SMTP server settings, including your Gmail credentials.

- **CSV Data Processing**:
  - The script reads recipient information from a CSV file, excluding the header row.
  - It iterates through the CSV rows, extracting recipient names and grades (e.g., math, English, science) for each recipient.

- **Email Composition and Sending**:
  - For each recipient, the script:
    - Creates an email message using the email template, replacing placeholders with specific recipient data.
    - Defines email parameters such as sender, recipient, and subject.
    - Attaches the message body to the email as plain text.
    - Sends the email via the configured SMTP server.

- **SMTP Server and Connection**:
  - The script establishes a connection to the Gmail SMTP server using secure transport (TLS) and logs in using your Gmail email and password.
  - Upon sending all emails, it terminates the SMTP session and closes the connection.

- **Execution**:
  - The `if __name__ == '__main__'` block ensures that the `main` function is executed when the script is run.

### Usage

1. Replace `'your_email@gmail.com'` and `'your_password'` with your actual Gmail email and password.
2. Ensure that you've allowed less secure apps in your Gmail account settings or consider using an "App Password" if two-factor authentication is enabled for your Gmail account.
3. Prepare your email template in a file named 'template.txt' with placeholders for recipient data.

**Note**: It's essential to handle sensitive information, such as email credentials, securely and follow security best practices when sending emails programmatically.

