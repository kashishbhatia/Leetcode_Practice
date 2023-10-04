class Solution {
public:

/*
simple python program

    def numUniqueEmails(self, emails: List[str]) -> int:
        seen = set()
        for email in emails:
            name, domain = email.split('@') 
            local = name.split('+')[0].replace('.', '')
            seen.add(local + '@' + domain)
        return len(seen)
        
*/

/*
simple C++ program

    int numUniqueEmails(vector<string>& emails)
    {
        for(auto& email:emails){
            auto at_location = find(email.begin(),email.end(),'@');
            auto end_after_removing_dots = remove(email.begin(),at_location,'.');
         auto plus_location = find(email.begin(),end_after_removing_dots,'+');
            email.erase(plus_location,at_location);
        }
        return unordered_set(emails.begin(),emails.end()).size();
    }


*/
    int numUniqueEmails(vector<string>& emails) {

        set <string> s;
        for (int i=0; i<emails.size(); i++) {
            stringstream email(emails[i]);

            string localName;
            getline(email, localName, '@');

            string domain;
            getline(email, domain, '@');

            //now correct the local name
            stringstream localTemp(localName);
            string firstName;
            getline(localTemp, firstName, '+'); //get name before 1st '+'

            stringstream filterDots(firstName);
            string finalLocalName;
            string token;

            while (getline(filterDots, token, '.')) {
                finalLocalName += token;
            }

            string email_i = finalLocalName + '@' + domain;
            s.insert(email_i);
        }

        return s.size();
    }
};
