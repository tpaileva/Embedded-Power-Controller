#ifndef _ROS_copilot_msgs_CopilotTaskRequest_h
#define _ROS_copilot_msgs_CopilotTaskRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace copilot_msgs
{

  class CopilotTaskRequest : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _id_type;
      _id_type id;
      typedef const char* _name_type;
      _name_type name;
      typedef int16_t _status_type;
      _status_type status;
      typedef const char* _requester_agent_type;
      _requester_agent_type requester_agent;
      typedef const char* _requester_module_type;
      _requester_module_type requester_module;
      typedef const char* _description_type;
      _description_type description;
      typedef const char* _prompt_message_type;
      _prompt_message_type prompt_message;
      typedef const char* _prompt_title_type;
      _prompt_title_type prompt_title;
      uint32_t parameters_length;
      typedef char* _parameters_type;
      _parameters_type st_parameters;
      _parameters_type * parameters;
      uint32_t agent_length;
      typedef char* _agent_type;
      _agent_type st_agent;
      _agent_type * agent;
      uint32_t resource_length;
      typedef char* _resource_type;
      _resource_type st_resource;
      _resource_type * resource;
      typedef int16_t _priority_type;
      _priority_type priority;
      uint32_t dependency_length;
      typedef char* _dependency_type;
      _dependency_type st_dependency;
      _dependency_type * dependency;
      typedef bool _delete_previous_requests_type;
      _delete_previous_requests_type delete_previous_requests;
      int16_t start_time[2];
      int16_t duration[2];
      typedef int16_t _deadline_type;
      _deadline_type deadline;
      uint32_t user_input_options_length;
      typedef char* _user_input_options_type;
      _user_input_options_type st_user_input_options;
      _user_input_options_type * user_input_options;
      typedef bool _allow_autonomous_execution_type;
      _allow_autonomous_execution_type allow_autonomous_execution;
      enum { PENDING = 1 };
      enum { INPROGRESS = 2 };
      enum { AUTOEXEC = 3 };
      enum { SUCCEEDED = 0 };
      enum { FAILED = -1 };
      enum { DELAYED = -2 };

    CopilotTaskRequest():
      header(),
      id(""),
      name(""),
      status(0),
      requester_agent(""),
      requester_module(""),
      description(""),
      prompt_message(""),
      prompt_title(""),
      parameters_length(0), st_parameters(), parameters(nullptr),
      agent_length(0), st_agent(), agent(nullptr),
      resource_length(0), st_resource(), resource(nullptr),
      priority(0),
      dependency_length(0), st_dependency(), dependency(nullptr),
      delete_previous_requests(0),
      start_time(),
      duration(),
      deadline(0),
      user_input_options_length(0), st_user_input_options(), user_input_options(nullptr),
      allow_autonomous_execution(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        int16_t real;
        uint16_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_status.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->status);
      uint32_t length_requester_agent = strlen(this->requester_agent);
      varToArr(outbuffer + offset, length_requester_agent);
      offset += 4;
      memcpy(outbuffer + offset, this->requester_agent, length_requester_agent);
      offset += length_requester_agent;
      uint32_t length_requester_module = strlen(this->requester_module);
      varToArr(outbuffer + offset, length_requester_module);
      offset += 4;
      memcpy(outbuffer + offset, this->requester_module, length_requester_module);
      offset += length_requester_module;
      uint32_t length_description = strlen(this->description);
      varToArr(outbuffer + offset, length_description);
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_description);
      offset += length_description;
      uint32_t length_prompt_message = strlen(this->prompt_message);
      varToArr(outbuffer + offset, length_prompt_message);
      offset += 4;
      memcpy(outbuffer + offset, this->prompt_message, length_prompt_message);
      offset += length_prompt_message;
      uint32_t length_prompt_title = strlen(this->prompt_title);
      varToArr(outbuffer + offset, length_prompt_title);
      offset += 4;
      memcpy(outbuffer + offset, this->prompt_title, length_prompt_title);
      offset += length_prompt_title;
      *(outbuffer + offset + 0) = (this->parameters_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->parameters_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->parameters_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->parameters_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->parameters_length);
      for( uint32_t i = 0; i < parameters_length; i++){
      uint32_t length_parametersi = strlen(this->parameters[i]);
      varToArr(outbuffer + offset, length_parametersi);
      offset += 4;
      memcpy(outbuffer + offset, this->parameters[i], length_parametersi);
      offset += length_parametersi;
      }
      *(outbuffer + offset + 0) = (this->agent_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->agent_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->agent_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->agent_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->agent_length);
      for( uint32_t i = 0; i < agent_length; i++){
      uint32_t length_agenti = strlen(this->agent[i]);
      varToArr(outbuffer + offset, length_agenti);
      offset += 4;
      memcpy(outbuffer + offset, this->agent[i], length_agenti);
      offset += length_agenti;
      }
      *(outbuffer + offset + 0) = (this->resource_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->resource_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->resource_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->resource_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->resource_length);
      for( uint32_t i = 0; i < resource_length; i++){
      uint32_t length_resourcei = strlen(this->resource[i]);
      varToArr(outbuffer + offset, length_resourcei);
      offset += 4;
      memcpy(outbuffer + offset, this->resource[i], length_resourcei);
      offset += length_resourcei;
      }
      union {
        int16_t real;
        uint16_t base;
      } u_priority;
      u_priority.real = this->priority;
      *(outbuffer + offset + 0) = (u_priority.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_priority.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->priority);
      *(outbuffer + offset + 0) = (this->dependency_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->dependency_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->dependency_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->dependency_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dependency_length);
      for( uint32_t i = 0; i < dependency_length; i++){
      uint32_t length_dependencyi = strlen(this->dependency[i]);
      varToArr(outbuffer + offset, length_dependencyi);
      offset += 4;
      memcpy(outbuffer + offset, this->dependency[i], length_dependencyi);
      offset += length_dependencyi;
      }
      union {
        bool real;
        uint8_t base;
      } u_delete_previous_requests;
      u_delete_previous_requests.real = this->delete_previous_requests;
      *(outbuffer + offset + 0) = (u_delete_previous_requests.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->delete_previous_requests);
      for( uint32_t i = 0; i < 2; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_start_timei;
      u_start_timei.real = this->start_time[i];
      *(outbuffer + offset + 0) = (u_start_timei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_start_timei.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->start_time[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_durationi;
      u_durationi.real = this->duration[i];
      *(outbuffer + offset + 0) = (u_durationi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_durationi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->duration[i]);
      }
      union {
        int16_t real;
        uint16_t base;
      } u_deadline;
      u_deadline.real = this->deadline;
      *(outbuffer + offset + 0) = (u_deadline.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_deadline.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->deadline);
      *(outbuffer + offset + 0) = (this->user_input_options_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->user_input_options_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->user_input_options_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->user_input_options_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->user_input_options_length);
      for( uint32_t i = 0; i < user_input_options_length; i++){
      uint32_t length_user_input_optionsi = strlen(this->user_input_options[i]);
      varToArr(outbuffer + offset, length_user_input_optionsi);
      offset += 4;
      memcpy(outbuffer + offset, this->user_input_options[i], length_user_input_optionsi);
      offset += length_user_input_optionsi;
      }
      union {
        bool real;
        uint8_t base;
      } u_allow_autonomous_execution;
      u_allow_autonomous_execution.real = this->allow_autonomous_execution;
      *(outbuffer + offset + 0) = (u_allow_autonomous_execution.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->allow_autonomous_execution);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      union {
        int16_t real;
        uint16_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_status.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->status = u_status.real;
      offset += sizeof(this->status);
      uint32_t length_requester_agent;
      arrToVar(length_requester_agent, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_requester_agent; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_requester_agent-1]=0;
      this->requester_agent = (char *)(inbuffer + offset-1);
      offset += length_requester_agent;
      uint32_t length_requester_module;
      arrToVar(length_requester_module, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_requester_module; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_requester_module-1]=0;
      this->requester_module = (char *)(inbuffer + offset-1);
      offset += length_requester_module;
      uint32_t length_description;
      arrToVar(length_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_description;
      uint32_t length_prompt_message;
      arrToVar(length_prompt_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_prompt_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_prompt_message-1]=0;
      this->prompt_message = (char *)(inbuffer + offset-1);
      offset += length_prompt_message;
      uint32_t length_prompt_title;
      arrToVar(length_prompt_title, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_prompt_title; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_prompt_title-1]=0;
      this->prompt_title = (char *)(inbuffer + offset-1);
      offset += length_prompt_title;
      uint32_t parameters_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->parameters_length);
      if(parameters_lengthT > parameters_length)
        this->parameters = (char**)realloc(this->parameters, parameters_lengthT * sizeof(char*));
      parameters_length = parameters_lengthT;
      for( uint32_t i = 0; i < parameters_length; i++){
      uint32_t length_st_parameters;
      arrToVar(length_st_parameters, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_parameters; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_parameters-1]=0;
      this->st_parameters = (char *)(inbuffer + offset-1);
      offset += length_st_parameters;
        memcpy( &(this->parameters[i]), &(this->st_parameters), sizeof(char*));
      }
      uint32_t agent_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      agent_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      agent_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      agent_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->agent_length);
      if(agent_lengthT > agent_length)
        this->agent = (char**)realloc(this->agent, agent_lengthT * sizeof(char*));
      agent_length = agent_lengthT;
      for( uint32_t i = 0; i < agent_length; i++){
      uint32_t length_st_agent;
      arrToVar(length_st_agent, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_agent; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_agent-1]=0;
      this->st_agent = (char *)(inbuffer + offset-1);
      offset += length_st_agent;
        memcpy( &(this->agent[i]), &(this->st_agent), sizeof(char*));
      }
      uint32_t resource_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      resource_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      resource_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      resource_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->resource_length);
      if(resource_lengthT > resource_length)
        this->resource = (char**)realloc(this->resource, resource_lengthT * sizeof(char*));
      resource_length = resource_lengthT;
      for( uint32_t i = 0; i < resource_length; i++){
      uint32_t length_st_resource;
      arrToVar(length_st_resource, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_resource; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_resource-1]=0;
      this->st_resource = (char *)(inbuffer + offset-1);
      offset += length_st_resource;
        memcpy( &(this->resource[i]), &(this->st_resource), sizeof(char*));
      }
      union {
        int16_t real;
        uint16_t base;
      } u_priority;
      u_priority.base = 0;
      u_priority.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_priority.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->priority = u_priority.real;
      offset += sizeof(this->priority);
      uint32_t dependency_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      dependency_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      dependency_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      dependency_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->dependency_length);
      if(dependency_lengthT > dependency_length)
        this->dependency = (char**)realloc(this->dependency, dependency_lengthT * sizeof(char*));
      dependency_length = dependency_lengthT;
      for( uint32_t i = 0; i < dependency_length; i++){
      uint32_t length_st_dependency;
      arrToVar(length_st_dependency, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_dependency; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_dependency-1]=0;
      this->st_dependency = (char *)(inbuffer + offset-1);
      offset += length_st_dependency;
        memcpy( &(this->dependency[i]), &(this->st_dependency), sizeof(char*));
      }
      union {
        bool real;
        uint8_t base;
      } u_delete_previous_requests;
      u_delete_previous_requests.base = 0;
      u_delete_previous_requests.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->delete_previous_requests = u_delete_previous_requests.real;
      offset += sizeof(this->delete_previous_requests);
      for( uint32_t i = 0; i < 2; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_start_timei;
      u_start_timei.base = 0;
      u_start_timei.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_start_timei.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->start_time[i] = u_start_timei.real;
      offset += sizeof(this->start_time[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_durationi;
      u_durationi.base = 0;
      u_durationi.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_durationi.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration[i] = u_durationi.real;
      offset += sizeof(this->duration[i]);
      }
      union {
        int16_t real;
        uint16_t base;
      } u_deadline;
      u_deadline.base = 0;
      u_deadline.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_deadline.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->deadline = u_deadline.real;
      offset += sizeof(this->deadline);
      uint32_t user_input_options_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      user_input_options_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      user_input_options_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      user_input_options_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->user_input_options_length);
      if(user_input_options_lengthT > user_input_options_length)
        this->user_input_options = (char**)realloc(this->user_input_options, user_input_options_lengthT * sizeof(char*));
      user_input_options_length = user_input_options_lengthT;
      for( uint32_t i = 0; i < user_input_options_length; i++){
      uint32_t length_st_user_input_options;
      arrToVar(length_st_user_input_options, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_user_input_options; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_user_input_options-1]=0;
      this->st_user_input_options = (char *)(inbuffer + offset-1);
      offset += length_st_user_input_options;
        memcpy( &(this->user_input_options[i]), &(this->st_user_input_options), sizeof(char*));
      }
      union {
        bool real;
        uint8_t base;
      } u_allow_autonomous_execution;
      u_allow_autonomous_execution.base = 0;
      u_allow_autonomous_execution.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->allow_autonomous_execution = u_allow_autonomous_execution.real;
      offset += sizeof(this->allow_autonomous_execution);
     return offset;
    }

    virtual const char * getType() override { return "copilot_msgs/CopilotTaskRequest"; };
    virtual const char * getMD5() override { return "0c68bd49b5aca0ab860f806640c4d8f4"; };

  };

}
#endif
