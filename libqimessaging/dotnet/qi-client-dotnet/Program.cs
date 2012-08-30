﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using QiMessaging;

namespace qi_client_dotnet
{
    class Program
    {
        static void Main(string[] args)
        {
            Application app = new Application(ref args);
            string connectionAddr;

            if (args.Length != 2)
            {
                Console.WriteLine("Usage : /qi-client-dotnet master-address");
                Console.WriteLine("Assuming master-address is tcp://127.0.0.1:5555");
                connectionAddr = "tcp://127.0.0.1:5555";
            }
            else
                connectionAddr = args[1];

            Session session = new Session();
            session.Connect(connectionAddr);
            session.WaitForConnected(3000);

            QiMessaging.Object obj = session.Service("serviceTest");

            if (obj == null)
            {
                Console.WriteLine("Ooops, can't get service");
                return;
            }

            Message message = new Message();
            message.WriteString("plaf");
            // It's gonna be...
            Future future = obj.Call("reply::s(s)", message);

            // wait for it
            future.Wait();

            if (future.IsError() == true)
                Console.WriteLine("An error occured");

            // LEGENDARY
            if (future.IsReady() == true && future.IsError() == false)
            {
                Message answer = future.GetValue();
                string value = answer.ReadString();
                Console.WriteLine("Reply: " + value);
            }

            session.Disconnect();
        }
    }
}
