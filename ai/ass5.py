import re

products = {
    "phone": 500,
    "laptop": 1000,
    "headphones": 100
}

def get_response(user_input):
    text = user_input.lower()

    if re.search(r'\b(hi|hello|hey)\b', text):
        return "Hello! How can I help you?"

    elif re.search(r'\b(price|cost)\b', text):
        for item in products:
            if re.search(item, text):
                return f"The price of {item} is ${products[item]}"
        return "Please specify the product."

    elif re.search(r'\b(refund|return)\b', text):
        return "You can return items within 7 days with receipt."

    elif re.search(r'\b(delivery|shipping)\b', text):
        return "Delivery takes 3-5 business days."

    elif re.search(r'\b(available|stock)\b', text):
        for item in products:
            if re.search(item, text):
                return f"Yes, {item} is available."
        return "Please specify the product."

    elif re.search(r'\b(thank you|thanks)\b', text):
        return "You're welcome!"

    elif re.search(r'\b(bye|exit|quit)\b', text):
        return "Goodbye!"

    else:
        return "Sorry, I didn't understand. Can you rephrase?"

print("Customer Support Chatbot")
print("Ask about price, availability, delivery, or returns.")
print("Type 'bye' to exit.\n")

while True:
    user_input = input("You: ")
    response = get_response(user_input)
    print("Bot:", response)
    if re.search(r'\b(bye|exit|quit)\b', user_input.lower()):
        break