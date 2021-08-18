## A Chatbot Class

In this assignment your task is to create a
[chatbot](https://en.wikipedia.org/wiki/Chatbot) that can, if possible, pass
[the Turing Test](https://en.wikipedia.org/wiki/Turing_test).

Implement your chatbot in a class called `Chatbot` in the file
[chatbot.h](chatbot.h). Test it using the code in
[chatbot_driver.cpp](chatbot_driver.cpp). **Important**: your code *must* work
with [chatbot_driver.cpp](chatbot_driver.cpp)! Implement, at least, all the
methods and constructors it requires. You can test your `Chatbot` class with
other code if you like, but it still must work with the unmodified
[chatbot_driver.cpp](chatbot_driver.cpp).

This is an open-ended assignment: your goal is to make your chatbot as
interesting and as intelligent as possible. It's fine if you want to restrict
your chatbot to a particular topic, e.g. it could just chat about hockey, or
Harry Potter, or geography, etc. You could try to make it useful, e.g. the
chatbot could help you learn C++ --- maybe it could even write programs for
you!

Some Functionality:
- **Keyword-style functionality**: Search the user input for particular
  keywords, and do something different for each keyword.

- **[Eliza][Eliza]-style functionality**: This follows the style of the famous
  [Eliza chatbot][Eliza]. This includes keyword-style functionality.

- **Beyond [Eliza][Eliza]-style functionality**: Something original, creative,
  or interesting that clearly and non-trivially goes beyond an
  [Eliza][Eliza]-style chatbot.


- **What is an [Eliza][Eliza]-style chatbot?**

  [Eliza][Eliza]-style chatbot asks the user questions based on their input.
  It looks for text patterns, such as "I like X", and responds with a matching
  pattern, such as "Why do you like X?". For example, if the user enters "I
  like to dream of sheep", the response would be "Why do you like to dream of
  sheep?"

  You should look for a number of different such patterns, the more the
  better. Here are a couple of other ideas for patterns and replies:

  - Given "I am X", reply with "How long have you been X?"

  - Given "You are X", reply with "Why do you think I am X?"

  - Given "I saw X in a dream", reply with "How does X make you feel?"

  The idea is to reply to the patterns in a way that encourages the human to
  give more details, to have them carry the conversation.

  You should add at least one of your own templates.

- **How can I go beyond an [Eliza][Eliza]-style chatbot?**

  It's not hard to see the limitations of [Eliza][Eliza]. For example, Eliza
  has no memory of anything you see. So one thing you might try is to remember
  some words, and then use them in later replies.

  Another problem with [Eliza][Eliza] is that it doesn't answer any useful
  questions. You could try adding templates designed to answer practical
  questions.

More on ELIZA:
[Eliza]: https://en.wikipedia.org/wiki/ELIZA
