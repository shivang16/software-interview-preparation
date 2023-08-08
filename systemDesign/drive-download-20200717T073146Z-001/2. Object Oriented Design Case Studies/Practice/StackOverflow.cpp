#include<bits/stdc++.h>

class Account{
    private: 
        string emailId;
        string name;
        string bio;
        /**other general information*/
};

class Moderator extends Account{
    private: 
        List <Questions> updatedQuestions;
};

class Member extends Account{
    private: 
        List <Badges> badges;    
        List <Questions> questions;
        List <Answers> answers;
};


class StackOverflow{

    List <Members> members;
    List <Moderator> moderators;
    List <Questions> questions;

    bool addMembers(Members member){};

    bool addModerator(Moderator moderator){};

    Question searchQuestion(string searchString){
        // Finds the question by using searchString and return;
    }

    bool createQuestion(Question question, Member memberId){
        // Check if memberId is null or not
        // Then create the question
    };

    bool addAnswer(string QuestionId, Member memberId, Answer answer){
        // Check if memberIs null or not
        // Then add answer
    };

    bool upVote(string QuestionId, Member memberId){};

    bool downVote(string QuestionId, Member memberId){};

    bool closeQuestion(string QuestionId, Member memberId){};

};


class Content{
    private:
        string contentId;
        string content;
        date createDate;
        date ModifiedDate;
        Account createdBy;
        int downVotes;
        int upVotes;
        int flagVotes;
    public: 
        // getters and setters
};

class Question extends Content{
    private: 
        string questionTitle;
        List <Comments> comments;
        List <Answers> answers; 
        int bounty;
        int closeQuestionVote;
        int deleteQuestionVote;
        List <Tags> questionTag;
        QuestionStatus questionStatus;
    public: 
        // getters and setters
};


class Comment extends Content{
        
};

class Answer extends Content{
    private: 
        List <Comment> comments;
        bool isAccepted;
    public:
        // getters and setters
};

enum QuestionStatus{
    'OPEN',
    'CLOSED',
    'DELETED'
};

enum Tags{
    'Java',
    'JS'
};

enum Badges{
    'GOLD',
    'SILVER'
};