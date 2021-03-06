﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace test
{
    class Program
    {
        static void Main()
        {
            Pro.AllConfigs config = new Pro.AllConfigs();
            string fileName = "../data/AllConfigs.bin";
            bool success = config.init(fileName);
             
            Console.Write(config.version());

            config.monster((Pro.monsterConfig s)=> {
                Console.WriteLine("--------------------------");
                Console.Write(s.ToString()); return false; }
            );
            
            Pro.roleConfig conf1 = config.role(1);                                                                    

            Console.Write(conf1.ToString());
            Console.WriteLine("--------------------------");
           
            Console.WriteLine("--------------------------");
            Pro.roleConfig conf = config.role(7102);
            Console.WriteLine("--------------------------");
            Console.Write(conf.ToString());
            Console.WriteLine("--------------------------");

            Console.WriteLine("******************************");
            return;
        }
    }
}