// events.h this is the main header file for event management system
#ifndef EVENTS_H // if the header is not defined, this is the first time including this file
#define EVENTS_H // then define it immediately to prevent future inclusions
// standard library included
#include <string> // to handle strings
#include <set> // used for ordered collections
#include <unordered_set> // used for fast lookups
#include <vector> // used for dynamic arrays
#include <iostream> // used for the i/o operations
#include <fstream> // used for file operations
#include <sstream> // used for string streams
#include <limits> // used for numeric limits
#include <map> // used for ordered key-value storage (std::map)
#include <ctime> // used for time functions
#include <iomanip> // used for output formatting
#include <cctype> // used for character handling
#include <chrono> // used for time management
#include <algorithm> // it provides STL algorithms which stands for : sorting, searching, transformations
#include <chrono> // allows multithreading which is creating + manage parallel tasks
#include <thread> // allows multithreading which is creating + manage parallel tasks


using namespace std; // using a standard namespace

enum eventType { // enumeration of the different types of events
    Conference_, Workshop_, Webinar_ // named that way to avoid any confusion
};

enum notificationType { // enumeration which defines all possible notification types for the event-related messages
    Event_postponement,Event_cancellation, Event_registration, Event_feedback
};

// this is forward declaration of both classes where they are defined elsewhere.
// this allows us to reference to any of both classes before the full definition
class User;
class Observer;

// an abstract base class called event
class Event {
protected:
    string event_name, creator_name, description, platform, date, time; // private event attributes with event's info
    int capacity; // stores max attendees
    set <User*> registrars; // registered users
    bool full; // the max capacity flag
    vector<Observer*> observers_; // an observer pointer to notify observers
    User* creator_user; // a pointer to the creator user

public:
    Event(); // a default constructor
    Event(string n, User* creator, string desc, string p, string d, string t, int c, int f); //parametrised constructor
    virtual ~Event() = default; // a virtual destructor

    // pure virtual functions
    virtual void displayDetails() const = 0; // shows the event's details
    static Event* eventBuilder(eventType Type, User* creator); // a factory method to create specific event types
    virtual void saveToFile(ofstream& file) = 0; // saves the event to file
    bool isFull(); // checks if the event has reached max capacity
    set<User*> getRegistrars(); // gets registered users in an event
    bool addRegistrar(User* user); // adds the user to registrars

    // getter functions to get the event's details
    string getName() const;
    User* getCreator() const;
    string getDescription() const;
    string getDate() const;
    string getTime() const;
    string getPlatform() const;
    int getCapacity() const;

    virtual string getType() const = 0; // pure virtual function that gets the event type
    void setDate(string newDate); // updates event date
    void setTime(string newTime); // updates event time

    // observer Methods
    void attach(Observer* observer); // it adds an observer to notification list
    void detach(Observer* observer); // it removes an observer from the notification list
    void notify(notificationType); // it notifies all observers about any event changes

};

// a derived class from base class event called conference
class Conference : public Event {
private:
    int duration; // a private attribute that checks the duration of a conference
public:
    Conference(); // a default constructor
    Conference(string n, User* creator, string desc, string p, string d, string t, int c, int dur); // a parametrised constructor
    ~Conference() override = default; // a destructor

    void displayDetails() const override; // an overridden virtual function to display conference related details
    static Event* create_event(User* creator); // a static factory method for conference creation
    void saveToFile(ofstream& file) override; // saves the conference's data into a file
    // a static load function that creates a conference object from the data stored in a file
    static Event* loadFromFile(const string& line);

    // getter functions
    string getType() const override;
    int getDuration() const;
};

// a derived class from base class event called webinar
class Webinar : public Event {
private:
    string host; // a private attribute that stores the host
public:
    Webinar(); // a default constructor
    Webinar(string n, User* creator, string desc, string p, string d, string t, int c, string h); // a parametrised constructor
    ~Webinar() override = default; // an overridden default destructor

    void displayDetails() const override; // this displays webinar related details
    static Event* create_event(User* creator); // this is a factory method for webinar creation
    void saveToFile(ofstream& file) override; // saves the webinar's data into a file
    // a static function that creates a webinar object from data stored in a file
    static Event* loadFromFile(const string& line);

    // getter functions
    string getType() const override;
    string getHost() const;
};

// a derived class from base class event called workshop
class Workshop : public Event {
private:
    string instructor; // a private attribute that stores the workshop's instructor
public:
    Workshop(); // a default constructor
    Workshop(string n, User* creator, string desc, string p, string d, string t, int c, string i); // a parametrised constructor
    ~Workshop() override = default; // an overridden default destructor

    void displayDetails() const override; // this displays workshop related details
    static Event* create_event(User* creator); // this is a factory method for webinar creation
    void saveToFile(ofstream& file) override; // saves the workshop's data into a file
    // a static function that creates a workshop object from data stored in a file
    static Event* loadFromFile(const string& line);

    // getter functions
    string getType() const override;
    string getInstructor() const;
};

extern set <Event*> allEvents; // declares a global set of event pointers

// an abstract base class to implement the observer pattern
class Observer{
    public:
        // a pure virtual function to receive updates from the observed subjects
        virtual void update(const string& eventName, const string& message ) = 0;
        virtual ~Observer() = default; // a virtual destructor
};

// a class called User derived from observer
class User : public Observer {
private:
    string username, password, email, affiliation; // private attributes to store user's info
public:
    User(); // a default constructor
    User(string u, string p, string e, string a = ""); // a parametrised constructor
    virtual ~User() = default; // a virtual destructor

    // receives event notifications
    virtual void update(const string& eventName, const string& message) override;

    void setUsername(string u); // sets the username
    string getUsername() const; // gets the username

    void setPassword(string p); // sets the password
    string getPassword() const; // gets the passwrod

    void setEmail(string e); // sets the email
    string getEmail() const; // gets the email

    void setAffiliation(string a); // set the affiliation
    string getAffiliation() const; // gets the affiliation

    set<Event*> get_scheduled_events(); // a function that loads all events scheduled by user
    set<Event*> get_registered_events(); // a function that loads all events registered by user
    void schedule_event(); // a function that allows the user to create + schedule an event
    void register_event(); // a function for the user to register into an event
    void viewUserEvents(); // a function that displays all events associated with a user
    bool isRegistered(Event* e); // checks if a user is registered for a specific event
    void postpone_meeting(); // a function to handle rescheduling of existing events
    void cancel_meeting(); // a function to cancel any scheduled events

    bool operator==(const string& otherUsername) const {
        return this->username == otherUsername;
    }

};

extern set <User*> allUsers; // declares a global set of event pointers

// a class that stores + manages feedback for events
class Feedback {
public:
    Feedback(); // a default constructor
    Feedback(const string& reviewerUsername,
             const string& eventName,
             const string& eventType,
             const string& eventDate ); // a parametrised constructor

    // General event rating
    void setGeneralRating(int rating); // sets general rating
    int getGeneralRating() const; // gets general rating

    // Aspect-based ratings
    void setDetailedRating(const string& aspect, int rating); // sets detailed rating (parameter: reference to aspect + rating)
    int  getDetailedRating(const string& aspect) const; // gets detailed rating (parameter: reference to aspect)
    const map<string,int>& getAllDetailedRatings() const; // gets all aspect ratings

    // Qualitative
    void setImprovementSuggestion(const string& s); // sets the suggestion ( parameters : reference to the string )
    string getImprovementSuggestion() const; // gets the suggestion

    void attach(Observer* observer); // attaches an observer to receive event notifications
    void detach(Observer* observer); // detaches an observer to stop receiving notifications
    void notify(); // notifies all attached observers about any event updates

    // Metadata access
    string getReviewerUsername() const;
    string getEventName() const;
    string getEventType() const;
    string getSubmissionTimestamp() const;
    void setEventDate(const string& eventDate); // sets the event date (parameter : reference to event date)
    string getEventDate() const; // gets the event date

    // I/O
    void display(bool) const; // prints the feedback
    bool collectFeedbackInteractive(const vector<string>& potentialAspects); // interactive feedback collection (returns true if submitted)
    void saveToFile() const; // saves feedback to the file
    bool isSubmittedBeforeEvent() const; // checks if the feedback was submitted before the event took place
    static void review_feedbacks(User* user); // a function that displays feedback for user's events

private:
    static string getCurrentTimestamp(); // gets the current time stamp
    static time_t convertTimestampToTime(const string& timestamp); // converts the timestamp string to time_t (comparisons)
    int generalRating_; // declaration of int variable to store the general rating
    map<string,int> detailedRatings_; // aspect - specific scores
    // declared string variables to store data
    string improvementSuggestion_;
    string eventDate_;
    string reviewerUsername_, eventName_, eventType_, submissionTimestamp_;
    vector<Observer*> observers_;
};

class Menu {
public:
    void setup(); // a function that initializes system data + loads saved state
    void start_menu(); // a function that displays the initial starting menu
    void main_menu(User* user); // the main interface after the user successfully logs in
    void search_menu(); // the main interface for the searching functions
    void feedback_menu(User* user); // an interface for feedback management
};

// Global functions
void signup(); // a function that handles a new user's sign-up
User* login(); // a function that handles user authentication + returns logged-in user
void loadEventsData(); // a function that loads event data from "events.txt" into the allEvents container
void loadUsersData(); // a function that loads user data from "users.txt" into the allUsers container
void saveEventsToFile(); // a function that saves event data info into a file
void saveUsersToFile(); // a function that saves user data info into a file
void search_by_name(); // searches for events by name
void search_by_date(); // searches for events by date
void search_by_type(); // searches for events by type
void loadingAnimation(int seconds);

template <typename T> void printMultiset(const set<T>& mset); // a utility template to print any set's contents

#endif // end of the EVENTS_H header
