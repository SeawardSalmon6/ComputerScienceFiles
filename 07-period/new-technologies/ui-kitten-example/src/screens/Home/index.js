import { Button } from "@ui-kitten/components";
import { AppLayout } from "../../components/AppLayout";
import { APP_ROUTES } from "../../routes/app.routes";
import { useAppNavigation } from "../../hooks/useAppNavigation";

import { HomeHeader } from "./HomeHeader";
import { MAIN_BOTTOM_TAB_OPTIONS } from "../../shared/mainBottomTabOptions";

export function HomeScreen() {
  const { getGoTo } = useAppNavigation();

  return (
    <AppLayout.Base header={<HomeHeader />}>
      <Button onPress={getGoTo(APP_ROUTES.DETAILS)}>Go to Details</Button>
    </AppLayout.Base>
  );
}
