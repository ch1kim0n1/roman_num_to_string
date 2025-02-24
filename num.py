def number_to_words(num):
    if num == 0:
        return "zero"
    
    below_twenty = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", 
                    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
    tens = ["", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]
    thousands = ["", "thousand", "million", "billion"]
    
    result = ""
    i = 0
    
    while num > 0:
        if num % 1000 != 0:
            chunk = ""
            n = num % 1000
            
            if n >= 100:
                chunk += below_twenty[n // 100] + " hundred "
                n %= 100
                
            if n >= 20:
                chunk += tens[n // 10] + " "
                n %= 10
                
            if n > 0:
                chunk += below_twenty[n] + " "
                
            result = chunk + thousands[i] + " " + result
            
        num //= 1000
        i += 1
        
    return result.strip()

def roman_to_int(s):
    total = 0
    prev_value = 0
    
    roman_values = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }
    
    for char in reversed(s):
        if char not in roman_values:
            return -1
            
        value = roman_values[char]
        if value < prev_value:
            total -= value
        else:
            total += value
        prev_value = value
        
    return total

if __name__ == "__main__":
    roman = input("Enter Roman numeral: ")
    result = roman_to_int(roman)
    
    if result == -1:
        print("Invalid Roman numeral!")
    else:
        print(f"Integer: {result}")
        print(f"Word: {number_to_words(result)}")