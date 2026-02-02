using System;

namespace TrigonometricCalculator
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Trigonometric Calculator");
            Console.WriteLine("1. Calculate in degrees");
            Console.WriteLine("2. Calculate in radians");
            Console.Write("Choose an option: ");
            int option = Convert.ToInt32(Console.ReadLine());

            Console.Write("Enter angle: ");
            double angle = Convert.ToDouble(Console.ReadLine());

            switch (option)
            {
                case 1:
                    angle = angle * Math.PI / 180;
                    break;
                case 2:
                    break;
                default:
                    Console.WriteLine("Invalid option");
                    return;
            }

            double sin = Math.Sin(angle);
            double cos = Math.Cos(angle);
            double tg = Math.Tan(angle);
            double ctg = 1 / tg;

            Console.WriteLine($"Sin: {sin}");
            Console.WriteLine($"Cos: {cos}");
            Console.WriteLine($"Tg: {tg}");
            Console.WriteLine($"Ctg: {ctg}");
        }
    }
}