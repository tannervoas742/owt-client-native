/*
 * Intel License
 */
#ifndef OMS_CONFERENCE_SIGNALINGCHANNELINTERFACE_H_
#define OMS_CONFERENCE_SIGNALINGCHANNELINTERFACE_H_
#include <functional>
#include <memory>
#include "talk/oms/sdk/include/cpp/oms/conference/conferenceuser.h"
#include "webrtc/rtc_base/json.h"
namespace oms {
namespace conference {
class ConferenceSocketSignalingChannel {
 public:
  virtual void AddObserver(ConferenceSignalingChannelObserver& observer) = 0;
  virtual void RemoveObserver(ConferenceSignalingChannelObserver& observer) = 0;
  virtual void Connect(
      const std::string& token,
      std::function<void(Json::Value& room_info,
                         std::vector<const conference::User> users)> on_success,
      std::function<void(std::unique_ptr<Exception>)> on_failure) = 0;
  virtual void SendSdp(
      Json::Value& options,
      std::string& sdp,
      bool is_publish,
      std::function<void(Json::Value& ack, std::string& stream_id)> on_success,
      std::function<void(std::unique_ptr<Exception>)> on_failure) = 0;
  virtual void SendStreamEvent(
      const std::string& event,
      const std::string& stream_id,
      std::function<void()> on_success,
      std::function<void(std::unique_ptr<Exception>)> on_failure) = 0;
  virtual void SendCustomMessage(
      const std::string& message,
      const std::string& receiver,
      std::function<void()> on_success,
      std::function<void(std::unique_ptr<Exception>)> on_failure) = 0;
  virtual void SendStreamControlMessage(
      const std::string& stream_id,
      const std::string& action,
      std::function<void()> on_success,
      std::function<void(std::unique_ptr<Exception>)> on_failure) = 0;
  virtual void Disconnect(
      std::function<void()> on_success,
      std::function<void(std::unique_ptr<Exception>)> on_failure) = 0;
};
}
}
#endif  // OMS_CONFERENCE_SIGNALINGCHANNELINTERFACE_H_