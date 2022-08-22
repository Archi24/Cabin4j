private void ThisAddIn_Startup(object sender, System.EventArgs e)
{
    SendEmailtoContacts();
}

private void SendEmailtoContacts()
{
    string subjectEmail = "Meeting has been rescheduled.";
    string bodyEmail = "Meeting is one hour later.";
    Outlook.MAPIFolder sentContacts = (Outlook.MAPIFolder)
        this.Application.ActiveExplorer().Session.GetDefaultFolder
        (Outlook.OlDefaultFolders.olFolderContacts);
    foreach (Outlook.ContactItem contact in sentContacts.Items)
    {
        if (contact.Email1Address.Contains("example.com"))
        {
            this.CreateEmailItem(subjectEmail, contact
                .Email1Address, bodyEmail);
        }
    }
}

private void CreateEmailItem(string subjectEmail,
       string toEmail, string bodyEmail)
{
    Outlook.MailItem eMail = (Outlook.MailItem)
        this.Application.CreateItem(Outlook.OlItemType.olMailItem);
    eMail.Subject = subjectEmail;
    eMail.To = toEmail;
    eMail.Body = bodyEmail;
    eMail.Importance = Outlook.OlImportance.olImportanceLow;
    ((Outlook._MailItem)eMail).Send();
}
