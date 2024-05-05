import { Button } from "@ui-kitten/components";
import { AppLayout } from "../../components/AppLayout";
import { APP_ROUTES } from "../../routes/app.routes";
import { useAppNavigation } from "../../hooks/useAppNavigation";

export function FavoritesScreen() {
  const { getGoTo } = useAppNavigation();

  return (
    <AppLayout.Base
      header={<AppLayout.Header title="Favorites" backTo={null} />}
      contentStyle={{
        flex: 1,
        justifyContent: "center",
        alignItems: "center",
      }}
    >
      <Button onPress={getGoTo(APP_ROUTES.HOME)}>Go to Home</Button>
    </AppLayout.Base>
  );
}
