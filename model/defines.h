#include <Wt/Dbo/Types>
#include <string>

namespace dbo = Wt::Dbo;

typedef std::map<std::string, void*> MapAny;
typedef std::pair<std::string, void*> PairAny;

#include "user.h"
#include "image.h"
#include "video.h"
#include "frame.h"

class User;
class Image;
class Video;
class Frame;

typedef dbo::collection<dbo::ptr<User> > Users;
typedef dbo::collection<dbo::ptr<Image> > Images;
typedef dbo::collection<dbo::ptr<Video> > Videos;
typedef dbo::collection<dbo::ptr<Frame> > Frames;
