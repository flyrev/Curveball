
class EngineBase::Event;

/** TODO:
	- Implement Player, Score, Goal, and let them inherit Token
	- Implement Timer, and create synchronization server<->client
	- Implement MessageClient and MessageServer

*/
class Token
{
public:
	enum TokenID
	{
	    YOU = 0, WALL = 1, BALL = 2, ME = 3,  SCORE = 4, GOAL = 5
    };
	static const int nTokens = 6;

	virtual void Update( EngineBase::Event * ) = {}; // Forced movement
	virtual void Update(  double t ) = 0; // Estimated movement
	virtual void Draw() = 0;
};

class EngineBase
{
protected:

	Token ** tokens;
	Timer * timer;
	double LastUpdateTime;
	/** UpdateTokens updates the position of all movable tokens, based on their current parameters. */
	void UpdateTokens()
	{
		double t = timer.GetTime() - LastUpdateTime;
		for ( int i = 0; i < Token::nTokens; i++)
			tokens->Update(t);
	}
public:
		struct Event {
			int TokenID;
			std::string message;
			double timestamp;
		};


		EngineBase( Timer * timer)
		timer(timer)
		{
			tokens = new Token*[Token::nTokens];

			tokens[Token::ME] = new Player();
			tokens[Token::YOU] = new Player();

			tokens[Token::BALL] = new Ball();
			tokens[Token::WALLS] = new Wall();
			tokens[Token::GOALS] = new Goal();
			tokens[Token::SCORE] = new Score();

			LastUpdateTime = timer->GetTime();
		}

		/** Drawgame should be called by whatever function is set as glutRenderFunc */
		void DrawGame()
		{
			for ( int i = 0; i < Token::nTokens; i++)
			{
				tokens[i]->Draw();
			}
		}

		/** Idle should be called by whatever function is set as glutIdleFunc */
		virtual void Idle() = 0;

		virtual ~EngineBase()
		{
			for ( int i = 0; i < Token::nTokens; i++)
				delete tokens[i];
			delete [] tokens;
		}
};

class ClientEngine : public EngineBase
{
	private:
		// Token alias
		Player & me;
		Wall & walls;

		// Network handling class
		MessageClient client;

	public:
		ClientEngine()
			: EngineBase()
			, me( *reinterpret_cast<Player*>(tokens[ Token::ME ]))
			, walls (*reinterpret_cast<Wall*>(tokens[ Token::WALLS]))
		{}

		/**This function should based on the event, update the affected token accordingly. */
		void Update( Event * ev )
		{
			token[ ev->TokenID]->Update( ev );
			delete ev;
		}

		// Entrypoint
		virtual void Idle()
		{

		}

		virtual ~ClientEngine();


};


class ServerEngine : public EngineBase
{

		// Token alias
		Player & p1;
		Player & p2;
		Wall & walls
		Goal & goals;
		Ball & ball;

		//Network
		MessageServer server;

	void HandleCollisions()
	{
		p1.HandleCollision( walls );
		p2.HandleCollision( walls );

		ball.HandleCollision( p1 );
		ball.HandleCollision( p2 );
		ball.HandleCollision( walls );
		ball.HandleCollision( goals );
	}

public:

		ServerEngine()
			: EngineBase()
			, p1(    *reinterpret_cast<Player*>(tokens[ Token::ME ]) )
			, p2(    *reinterpret_cast<Player*>(tokens[ Token::YOU ]) )
			, walls( *reinterpret_cast<Wall*>  (tokens[ Token::WALLS ]) )
			, goals( *reinterpret_cast<Goal*>  (tokens[ Token::GOALS ]) )
			, ball(  *reinterpret_cast<Ball*>  (tokens[ Token::BALL ]) )
		{

		}


		// Entry point
		virtual void Idle()
		{

		}

		virtual ~ServerEngine();

};



