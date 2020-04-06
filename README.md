# wit
Lightweight version control system for websites

## Quick-Start
* copy the `wit/` directory to your htdocs folder 
* using your `.htaccess`, deny access to any of the items in the directory except index.php.
* Create an entry in `wit/auth.json` with your details, in this format:
```
{
   'name': <Your Full Name>,
   'username': <Your username>,
   'passowrd': <Your password in plaintext>
}
```

* You're ready to go.