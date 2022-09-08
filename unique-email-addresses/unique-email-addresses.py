class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        valid = {}
        for email in emails:
            email = email.split("@")
            name = email[0]
            domain = email[1]
            keep = name.split("+")[0].replace(".", "")
            key = keep + "@" + domain
            valid[key] = 1
        
        return len(valid)