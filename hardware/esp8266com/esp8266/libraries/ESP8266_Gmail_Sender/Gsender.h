/* Gsender class helps send e-mails from Gmail account
*  using Arduino core for ESP8266 WiFi chip
*  by Boris Shobat
*  September 29 2016
*/
#ifndef G_SENDER
#define G_SENDER
#define GS_SERIAL_LOG_1         // Print to Serial only server responce
//#define GS_SERIAL_LOG_2       //  Print to Serial client commands and server responce
#include <WiFiClientSecure.h>

class Gsender
{
    protected:
        Gsender();
    private:
        int SMTP_PORT ;
        char* SMTP_SERVER = "";
        char* EMAILBASE64_LOGIN = "";
        char* EMAILBASE64_PASSWORD = "";
        char* FROM = "";
        const char* _error = nullptr;
        char* _subject = nullptr;
        String _serverResponce;
        static Gsender* _instance;
        bool AwaitSMTPResponse(WiFiClientSecure &client, const String &resp = "", uint16_t timeOut = 10000);

    public:
        static Gsender* Instance();
        Gsender* Subject(const char* subject);
        Gsender* Subject(const String &subject);
        bool Send(const String &to, const String &message);
        String getLastResponce();
        const char* getError();
		
		void SMTP_PORT2(int Port);
		void SMTP_SERVER2(char* Server);
		void EMAILBASE64_LOGIN2(char* LOGIN);
		void EMAILBASE64_PASSWORD2(char* PASSWORD);
		void Send2(String Subject,String Message,String To);
};
#endif // G_SENDER
