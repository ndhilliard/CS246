#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <string>
#include <sstream>
#include "Util.h"

namespace ds
{
	class Token : public Object
	{ 
		private:
		static bool used;
		static unsigned int count;
		std::string key;
		int value;
		int alter;
		std::string cover;
		bool hidden;

		int Value() const 
		{
			return ((!used)?(alter):(value));
	       	}

		public:
		Token() : Token(std::string(), 0) {}
		
		Token(std::string key, int value)
		{	
			this->key = key;
			this->value = value;
			this->alter = value;
			this->cover = std::string();
			this->hidden = false;
		}

		Token(const Token& obj) { *this = obj; }

		Token& operator=(const Token& rhs)
		{
			if(this != &rhs)
			{
				key = rhs.key;
				value = rhs.value;
				alter = rhs.value;
				cover = rhs.cover;
				hidden = rhs.hidden;
			}
			return *this;
		}

		~Token() {}

		void Hide(std::string value)
		{
			cover = value;
			hidden = true;
		}

		static void Suspend(unsigned int value)
		{
			if(value > 0 && value < 100)
			{
				count = value;
			}
		}

		bool IsHidden() const { return hidden; }

		std::string Key() const { return key; }

		void Reveal() { hidden = false; }

		std::string ToString() const override 
		{
			return ((hidden)?(cover):(key));
		}

		void Alter(int value) 
		{ 
			used = false;
			alter = value; 
		}

		void Reset() { alter = value; }

		friend bool operator==(const Token& lhs, const Token& rhs)
		{
			bool result = lhs.Value() == rhs.Value();
			if(count > 0)
			{
				count -= 1;
			}
			else
			{
				used = true;
			}
			return result;
		}

		friend bool operator!=(const Token& lhs, const Token& rhs)
		{
			bool result = lhs.Value() != rhs.Value();
			if(count > 0)
			{
				count -= 1;
			}
			else 
			{
				used = true;
			}
			return result;
		}

		friend bool operator<(const Token& lhs, const Token& rhs)
		{
			bool result = lhs.Value() < rhs.Value();
			if(count > 0)
			{
				count -= 1;
			}
			else 
			{
				used = true;
			}
			return result;
		}

		friend bool operator>(const Token& lhs, const Token& rhs)
		{
			bool result = lhs.Value() > rhs.Value();
			if(count > 0)
			{
				count -= 1;
			}
			else 
			{
				used = true;
			}
			return result;
		}

		friend bool operator<=(const Token& lhs, const Token& rhs)
		{
			bool result = lhs.Value() <= rhs.Value();
			if(count > 0)
			{
				count -= 1;
			}
			else 
			{
				used = true;
			}
			return result;
		}
		
		friend bool operator>=(const Token& lhs, const Token& rhs)
		{
			bool result = lhs.Value() >= rhs.Value();
			if(count > 0)
			{
				count -= 1;
			}
			else 
			{
				used = true;
			}
			return result;
		}

		friend int operator-(const Token& lhs, const Token& rhs)
		{
			int result = lhs.Value() - rhs.Value();

			if(result < 0)
			{
				result *= -1;
			}
			
			if(count > 0)
			{
				count -= 1;
			}
			else
			{
				used = true;
			}
			return result;
		}	
	};

	bool Token::used = false;
	unsigned int Token::count = 0;

	class Collection : public Object
	{
		public:
		virtual void Insert(const Token&, std::string) = 0;
		virtual void Remove(std::string) = 0;
		virtual Token& View(std::string) = 0;
		virtual const Token& View(std::string) const = 0;
		virtual void Extend(bool) = 0;
		virtual long Size() const = 0;
		virtual bool Empty() const = 0;
		virtual void Clear() = 0;
		virtual std::string Info() const = 0;
	};

	class Program : public Object
	{
		public:
		virtual void Initialize() = 0; 
		virtual void Move(std::string) = 0;
		virtual bool Undo() = 0;
		virtual bool Completed() const = 0;
		virtual std::string State() const = 0;
		virtual std::string Info() const = 0;
	};
}

#endif // TOOLS_H
