import { Button } from "@ui-kitten/components";
import { AppLayout } from "../../components/AppLayout";
import { APP_ROUTES } from "../../routes/app.routes";
import { useAppNavigation } from "../../hooks/useAppNavigation";
import { TextAppearancesShowcase } from "../../components/Examples/Text2";
import { TextCategoriesShowcase } from "../../components/Examples/Text";
import { TextStatusesShowcase } from "../../components/Examples/Text3";

export function FavoritesScreen() {
  const { getGoTo } = useAppNavigation();

  return (
    <AppLayout.Base
      header={<AppLayout.Header title="Favorites" backTo={APP_ROUTES.HOME} />}
      contentStyle={{
        flex: 1,
        justifyContent: "center",
        alignItems: "center",
      }}
    >
      <Button onPress={getGoTo(APP_ROUTES.HOME)}>Go to Home</Button>
      <TextAppearancesShowcase />
      <TextCategoriesShowcase />
      <TextStatusesShowcase />
    </AppLayout.Base>
  );
}
