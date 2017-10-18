#pragma once


// This is used to make classes NonCopyable. Those classes which inherit from this class become
// noncopyable.
struct NonCopyable
{
	NonCopyable() = default;
	NonCopyable(const NonCopyable&) = delete;
	NonCopyable operator=(const NonCopyable&) = delete;
};