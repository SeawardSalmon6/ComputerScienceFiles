import { Icon } from "@ui-kitten/components";
import { APP_ROUTES } from "../routes/app.routes";

export const MAIN_BOTTOM_TAB_OPTIONS = [
  {
    key: "home",
    icon: <Icon name="home-outline" />,
    screenName: APP_ROUTES.HOME,
  },
  {
    key: "heart",
    icon: <Icon name="heart-outline" />,
    screenName: APP_ROUTES.FAVORITES,
  },
];
