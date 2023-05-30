import re
def message_probability(message,list_of_words,single_response=False,required_words=[]):
    message_certainity=0
    has_required_words=True

    for word in message:
        if word in list_of_words:
            message_certainity+=1

    percentage= float(message_certainity)/ float(len(list_of_words))

    for word in required_words:
        if word not in message:
            has_required_words=False
            break
    if has_required_words or single_response:
        return int(percentage*100)
    else:
        return 0    

def check_all_message(user_message):
    highesh_prob_list={}

    def response(bot_response,list_of_words,single_response=False,required_words=[]):
        nonlocal highesh_prob_list
        highesh_prob_list[bot_response]=message_probability(user_message,list_of_words,single_response,required_words)
    
    response("hello",['hello','hii','hey','ho'],single_response=True)
    response('Im an AI so I am always fine what about you?',['How','are','you','doing'],required_words=['how'])
    
    best_match=max(highesh_prob_list,key=highesh_prob_list.get)
    return best_match

def get_response(user_message):
    message=re.split(r'\s+|[,.*!?;]\s*',user_message.lower())
    response=check_all_message(message)
    return response




while True:
    message=input("You:")
    print('Bot : '+ get_response(message))
    