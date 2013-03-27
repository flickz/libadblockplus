#include <iostream>
#include <sstream>

#include "SubscriptionsCommand.h"

SubscriptionsCommand::SubscriptionsCommand(AdblockPlus::JsEngine& jsEngine)
  : Command("subscriptions"), jsEngine(jsEngine)
{
}

void SubscriptionsCommand::operator()(const std::string& arguments)
{
  std::istringstream argumentStream(arguments);
  std::string action;
  argumentStream >> action;
  if (!action.size())
  {
    ShowSubscriptions();
    return;
  }

  if (action == "update")
  {
    UpdateSubscriptions();
    return;
  }

  std::string url;
  argumentStream >> url;

  if (action == "add")
  {
    AddSubscription(url);
    return;
  }

  if (action == "remove")
  {
    RemoveSubscription(url);
    return;
  }

  throw NoSuchCommandError(name + " " + action);
}

std::string SubscriptionsCommand::GetDescription() const
{
  return "List and manage subscriptions";
}

std::string SubscriptionsCommand::GetUsage() const
{
  return name + " [add URL|remove URL|update]";
}

void SubscriptionsCommand::ShowSubscriptions()
{
  // TODO: List all subscriptions
}

void SubscriptionsCommand::AddSubscription(const std::string& url)
{
  // TODO: Add a subscriptions
}

void SubscriptionsCommand::RemoveSubscription(const std::string& url)
{
  // TODO: Remove a subscription
}

void SubscriptionsCommand::UpdateSubscriptions()
{
  // TODO: Update all subscriptions
}
