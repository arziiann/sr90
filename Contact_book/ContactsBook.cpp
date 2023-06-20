#include <iostream>
#include <tuple>
#include <vector>
#include <fstream>
#include <sstream>

class Mail
{
    private:
        std::string m_mail;

    public:
       bool check_mail(std::string mail)
       {
            int size = mail.size();
            for(int i = size - 1; i >= 0; --i)
            {
                if(mail[i] == '@' && mail[i + 1] == 'g' && mail[i + 2] == 'm' && mail[i + 3] == 'a' && mail[i + 4] == 'i' && mail[i + 5] == 'l' 
                && mail[i + 6] == '.' && mail[i + 7] == 'c' && mail[i + 8] == 'o' && mail[i + 9] == 'm')
                {
                    return 1;
                }
                if(mail[i] == '@' && mail[i + 1] == 'm' && mail[i + 2] == 'a' && mail[i + 3] == 'i' && mail[i + 4] == 'l' && mail[i + 5] == '.' 
                && mail[i + 6] == 'r' && mail[i + 7] == 'u')
                {
                    return 1;
                }
                
            }
            return 0;
        
       }

        std::string get()//kardum er
        {
            return m_mail;
        }
        
        void set(std::string mail)//dnum er
        {
            if(check_mail(mail))
            {
                m_mail = mail;
            }
        }


};

class PhoneNumber
{
    private:
        std::string phone_number;

    public:
        bool check_phone_number(std::string phone_number)
        {
            if(phone_number.size() == 12)
            for(int i = 0; i < phone_number.size(); ++i)
            {
               
                if(phone_number[i] == '+' && phone_number[i + 1] == '3' && phone_number[i + 2] == '7' && phone_number[i + 3] == '4')
                {
                    return 1;
                }
            }
            return 0;
        }
        std::string get()
        {
            return phone_number;
        }

        

        void set(std::string number )
        {
            if(check_phone_number(number))
            {
                phone_number = number;
            }
        }
};

class AddressBook
{
    private:
        std::vector<std::tuple<int, std::string, std::string, PhoneNumber, Mail> > data;
        int id = 0;
        std::fstream file;

    public:
        AddressBook()
        {
            if (!file.is_open())
            {
                file.open("data.txt");
            }
            
            std::string line;
            int counter = 0;
            std::string name;
            std::string surname;
            Mail mail;
            PhoneNumber phone;

            while (std::getline(file, line))
            {
                std::string word;
                std::stringstream stream(line);

                while (stream >> word)
                { 
                    switch (counter)
                    {
                    case 0:
                        id = std::stoi(word);
                        break;

                    case 1:
                        name = word;
                        break;

                    case 2:
                        surname = word;
                        break;

                    case 3:
                        phone.set(word); 
                        break;
                    case 4:
                        mail.set(word); 
                        break;

                    default:
                        break;
                    }
                    
                    ++counter;
                    
                }
                counter = 0;
                data.push_back(std::make_tuple(id, name, surname, phone, mail));
            }
        }

        ~AddressBook()
        {
            file.close();
            file.open("data.txt", std::ios::out | std::ios::trunc);
            for (int i = 0; i < data.size(); i++)
            {
                file << std::get<0>(data[i]) << " ";
                file << std::get<1>(data[i]) << " ";
                file << std::get<2>(data[i]) << " ";
                file << std::get<3>(data[i]).get() << " ";
                file << std::get<4>(data[i]).get() << "\n";
            }
            
            file.close();
        }
    int GetSize() const
    {
        return data.size();
    }
    void Add(std::string name, std::string surname, std::string phone, std::string mail)
    {
        Mail mail_input;
        mail_input.set(name);

        PhoneNumber ph_number;
        ph_number.set(phone);
        data.push_back(std::make_tuple(++id, name, surname, ph_number, mail_input));
    }
    void Find(std::string name)
    {
        for (int i = 0; i < data.size(); ++i)
        {
            if(std::get<1>(data[i]) == name)
            {
                std::cout << std::get<0>(data[i]) << std::endl;
                std::cout << std::get<1>(data[i]) << std::endl;
                std::cout << std::get<2>(data[i]) << std::endl;
                std::cout << std::get<3>(data[i]).get() << std::endl;
                std::cout << std::get<4>(data[i]).get() << std::endl;
            }
        }
        
    }

    void ShowContacts()
    {
        for (int i = 0; i < data.size(); ++i)
        {
            std::cout << std::get<0>(data[i]) << std::endl;
            std::cout << std::get<1>(data[i]) << std::endl;
            std::cout << std::get<2>(data[i]) << std::endl;
            std::cout << std::get<3>(data[i]).get() << std::endl;
            std::cout << std::get<4>(data[i]).get() << std::endl;
            
        }

    }
        //data.push_back(std::make_tuple(id, name, surname, phone, mail));


    void Update(int id,std::string name, std::string surname, std::string phone, std::string mail )
    {
        Mail _mail;
        _mail.set(mail);
        PhoneNumber _number;
        _number.set(phone);
        
        data[id - 1] = std::make_tuple(id, name, surname, _number, _mail);

    }

    void Remove(int id)
    {
        data.erase(data.begin() + (id - 1));
        
    }
    void UpdateIDs()
    {
        for (int i = 0; i < data.size(); ++i)
        {
            std::get<0>(data[i]) = i + 1;
        }
    }

};


int main()
{
   while(true) 
   {
    std::cout << "\n";
    std::cout << "1.If you want to see the ContactBook, press 1" << "\n";
    std::cout << "\n";
    std::cout << "2.If you want to add a new contact to ContactBook, press 2 and enter the relevant data" << "\n";
    std::cout << "\n";
    std::cout << "3.If you want to see the contact information under the corresponding name, press 3" << "\n";
    std::cout << "\n";
    std::cout << "4.If you want to delete the contact information under the corresponding id, press 4 and enter the id" << "\n";
    std::cout << "\n";
    std::cout << "5.If you want to update Contact Book contacts, press 5, and enter the id and the data you want to change under that id" << "\n";
    
    int number = 0; 
    std::cout << "\n";
    std::cout << "Enter Command: ";
    std::cin >> number;
        
        AddressBook book;   
        Mail check_mail; 
        PhoneNumber check_phone_number;
        switch (number)
        {
            case 1:
            {
                book.ShowContacts();
                break;
            }
            case 2:
            {
                std::string name, surname, phone, mail;
                std::cout << "Enter name: ";
                std::cin >> name;
                std::cout << "Enter surname: ";
                std::cin >> surname;
                std::cout << "Enter phone number: ";
                std::cin >> phone;
                while(check_phone_number.check_phone_number(phone) == 0)
                {
                    std::cout << "Enter phone number: ";
                    std::cin >> phone;
                }
                std::cout << "Enter  mail: ";
                std::cin >> mail;
                while(check_mail.check_mail(mail) == 0)
                {
                    std::cout << "Enter  mail: ";
                    std::cin >> mail;
                }   
                book.Add(name, surname, phone, mail);
                break;
            }
            case 3:
            {
                std::string name;
                std::cout << "Enter name: ";
                std::cin >> name;
                book.Find(name);
                break;
            }
            case 4:
            {
                int id = 0;
                std::cout << "Enter id: ";
                std::cin >> id;
                while(id <= 0 || id > book.GetSize())
                {
                    std::cout << "Enter id: ";
                    std::cin >> id;
                }
                book.Remove(id);
                book.UpdateIDs();
                book.ShowContacts();
                break;
            }
            case 5:
            {
                int id = 0;
                std::string name, surname, phone, mail;
                std::cout << "Enter id: ";
                std::cin >> id;
                std::cout << "Enter name: ";
                std::cin >> name;
                std::cout << "Enter surname: ";
                std::cin >> surname;
                std::cout << "Enter phone number: ";
                std::cin >> phone;
                while(check_phone_number.check_phone_number(phone) == 0)
                {
                    std::cout << "Enter phone number: ";
                    std::cin >> phone;
                }
                std::cout << "Enter  mail: ";
                std::cin >> mail;
                while(check_mail.check_mail(mail) == 0)
                {
                    std::cout << "Enter  mail: ";
                    std::cin >> mail;
                }       
                book.Update(id, name, surname, phone, mail);
                break;

            }

            default:
            break;
        } 
    }
}
