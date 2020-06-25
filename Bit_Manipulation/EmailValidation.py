import re
email = input ("Please type in an email address ")
if re.match("\A(?P<name>[\w\-_]+)@(?P<domain>[\w\-_]+).(?P<toplevel>[\w]+)\Z",email,re.IGNORECASE):
    print("Email is valid")
else:
    print("Email is invalid")