//Check prime number
bool isPrime(int number)
{
    if(number<=1)    
    {
        return true;
    }
    else
    {
       for(int i=2; (i*i)<=number; i++)
       {
          if(number % i == 0 ) return false;
       }
       return true;
    }
}
